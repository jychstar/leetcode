#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int row = 0; row != m; row++)
            for (int col = 0; col != n; col++) {
                if ((row == 0) && (col > 0)) grid[row][col] += grid[row][col - 1];
                if ((row > 0) && (col == 0)) grid[row][col] += grid[row - 1][col];
                if ((row > 0) && (col > 0)) grid[row][col] += min(grid[row][col - 1], grid[row - 1][col]);
            }
        return grid[m - 1][n - 1];
    }
};


int main() {
   vector<vector<int>> v2;
    v2.push_back({2,3});
    v2.push_back({3,4});
    v2.push_back({6,5});
    v2.push_back({4,1});

    Solution s;
    cout<< s.minPathSum(v2)<<endl;

    return 0;

}

