#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    string convert(string s, const int numRows) {

        if (numRows==1) return s;
        int period = numRows*2-2;
        vector<string> rows(numRows);
        for (int i=0; i!=s.size();i++) {
            int j = i % period; // get row number
            if (j >= numRows)
                j = period - j;
            rows[j] += s.at(i); // add to corresponding row
        }
        string ss="";
        for (string row: rows)
            ss += row;
        return ss;

    }
};


int main() {
   vector<int> v = {1,2,1,2,4};
    string s = "hello";
    //for (int i=0; i!=s.size();i++)
      //  cout<<s[i]<<endl;




    cout<< Solution().convert(s,3) <<endl;

    return 0;

}

