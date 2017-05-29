class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); 
        if (m==0) return 0;
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i!= m; i++)
            for (int j=0; j!=n; j++)
                if (grid[i][j] == '1'){
                    cnt += 1;
                    expanse(grid, i,j);
                }
        return cnt;
    }

    void expanse(vector<vector<char>>& grid,int i, int j){
        int m = grid.size(), n = grid[0].size();
        if (i<0 ||i==m || j<0 ||j==n)
            return;
        if (grid[i][j] == '1') {
            grid[i][j] = '0';     // set all the connections to 0
            expanse(grid, i-1,j);
            expanse(grid, i+1,j);
            expanse(grid, i,j-1);
            expanse(grid, i,j+1);
        }

    }
};