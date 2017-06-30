package etl;

import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.DriverManager;
import java.util.Arrays;
import java.io.*;

public class etl {

	// parse csv file and return sql insert string
	private static String parse_wafer_meta(String csvFile, String timestamp)
			throws IOException {
		String line = "";
		String product = ""; // sql is all string, no need int
		String tapeout = "";
		String lot = "";
		String wafer = "";
		String map = "";
		try {
			FileReader file = new FileReader(csvFile);
			BufferedReader buffer = new BufferedReader(file);
			while ((line = buffer.readLine()) != null) {
				String[] words = line.split(",");
				if (words.length == 2) {
					if (words[0].equals("Product")) {
						product = words[1];
					}
					if (words[0].equals("TapeoutVer")) {
						tapeout = words[1];
					}
					if (words[0].equals("Lot")) {
						lot = words[1];
					}
					if (words[0].equals("Wafer")) {
						wafer = words[1];
					}
					if (words[0].equals("MapName")) {
						map = words[1];
					}
				} // end if
			} // end while
			buffer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

		String sql = "insert into table wafer_meta values (" + product + ",'"
				+ tapeout + "','" + lot + "'," + wafer + ",'" + map + "','"
				+ timestamp + "')";
		System.out.println("running: " + sql);
		return sql;
	}

	// main method: parse csv file name, put content in database table by its
	// kind
	public static void main(String[] args) throws SQLException, IOException {

		try {
			Class.forName("org.apache.hive.jdbc.HiveDriver");
		} catch (ClassNotFoundException ex) {
			System.out.println("Error: unable to load driver class!");
			System.exit(1);
		}
		// get connection, user and password are ignored in non-secured mode
		Connection con = DriverManager.getConnection(
				"jdbc:hive2://localhost:10000/default", "cloudera", "cloudera");
		Statement stmt = con.createStatement();

		java.util.Properties props = System.getProperties();
		String pwd = props.get("user.dir").toString();
		ResultSet res;
		ResultSetMetaData metadata;
		String sql;
		String timestamp;
		int wafer;
		String lot;

		
		// run this to avoid repeatedly adding into table
		sql = "drop table if exists wafer_meta "; 
		stmt.execute(sql);
		sql = "drop table if exists bc_partition "; 
		stmt.execute(sql);
		
		// create table wafer_meta
		sql = "create table if not exists wafer_meta (product int, tapeoutvet String,lot string, wafer int, mapname String, timestamp String)";
		stmt.execute(sql);

		// create table bc_cache for loading raw BC_file
		sql = "create table if not exists bc_cache (wafer int, test_time String,die_name String, microsite String, wavelength float, power float, voltage float) "
				+ " row format delimited fields terminated by ',' lines terminated by  '\n' tblproperties('skip.header.line.count'='1')";
		stmt.execute(sql);

		// create table bc_partition
		sql = "create table if not exists bc_partition (wavelength float, power float, voltage float) partitioned by (lot string, wafer int, test_time string)";
		stmt.execute(sql);
		// set dynamic partition
		sql = "set hive.exec.dynamic.partition.mode=nonstrict";
		stmt.execute(sql);

		int csv_count = 0;
		File a = new File("./");
		String[] paths = a.list(); // list all files, directories
		Arrays.sort(paths); // make sure the meta info file come first
		for (String path : paths) {
			if (path.contains(".csv")) {
				csv_count++;
				String reduced_file_name = path.replace(".csv", "");
				String[] parsed_file_name = reduced_file_name.split("_");
				if ((parsed_file_name.length == 6)
						&& (parsed_file_name[0].equals("Param"))) {
					timestamp = parsed_file_name[5];
					System.out.println("processing: "+ path);
					sql = parse_wafer_meta(path, timestamp);
					stmt.execute(sql);
				} else if ((parsed_file_name.length == 7)
						&& (parsed_file_name[0].equals("Param"))) {
					if (parsed_file_name[6].equals("BC")) {
						System.out.println("BC: " + path);
						wafer = Integer.parseInt(parsed_file_name[2]);
						timestamp = parsed_file_name[5];
						sql = "select lot from wafer_meta where wafer ="
								+ wafer + " and timestamp = '" + timestamp
								+ "'";
						System.out.println("Running : " + sql);
						res = stmt.executeQuery(sql);
						System.out.println(" lot ");
						if (res.next()) {
							lot = res.getString(1); // most important key: lot
													// is found
							System.out.println(lot);

							// load raw BC_file into table
							sql = "load data local inpath '" + pwd + "/" + path
									+ "'overwrite into table bc_cache";
							System.out.println("running: " + sql);
							stmt.execute(sql);

							sql = "insert into table bc_partition partition(lot='"
									+ lot
									+ "',wafer ="
									+ wafer
									+ ", test_time)select wavelength, power, voltage, test_time from bc_cache";
							System.out.println("running: " + sql);
							stmt.execute(sql);
						} else {
							System.out
									.println("lot not found, meta info missing, check later");
						}

					}
					if (parsed_file_name[6].equals("CD")) {
						System.out.println("CD: " + path);
					}
				} else {
					System.out.println("csv file has unknown kind: " + path);
				} // end analyze file name
			} // end (path.contains(".csv"))
		} // end foreach loop
		System.out.println("total csv files: " + csv_count);
		
		// example query: get map location, given product, tapeout and lot string
		int product = 2525;
		String tapeoutvet = "Dr.B";
		lot = "W6493020";
				
		sql = "select lot, wafer, mapname from wafer_meta where product = "+ product + " and tapeoutvet = '" + tapeoutvet + "' and lot = '" + lot + "'";
		System.out.println("running: " + sql);
		res = stmt.executeQuery(sql);
        metadata = res.getMetaData(); 
        int columnCount = metadata.getColumnCount();
        for (int i = 1; i <= columnCount; i++) 
          { System.out.print(metadata.getColumnName(i) + "\t "); } 
        System.out.println();
        while (res.next()) 
        { String row = "";
          for (int i = 1; i <= columnCount; i++)
              { row += res.getString(i) + ", "; } 
          System.out.println(row); 
          }

		// example query: get median wavelength trend over time
        // previous query has given user the wafer number
		sql = "select test_time, percentile_approx(wavelength, 0.5) from bc_partition where lot='W6493020' and wafer=68 group by test_time";
		System.out.println("running: " + sql);
		res = stmt.executeQuery(sql);
        metadata = res.getMetaData(); 
        columnCount = metadata.getColumnCount();
        for (int i = 1; i <= columnCount; i++) 
          { System.out.print(metadata.getColumnName(i) + "\t "); } 
        System.out.println();
        while (res.next()) 
        { String row = "";
          for (int i = 1; i <= columnCount; i++)
              { row += res.getString(i) + ", "; } 
          System.out.println(row); 
          }
		

		con.close();
	}
}