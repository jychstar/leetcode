#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i)
            for (int j = 0; j < i + 1; ++j){
                int m =  min(triangle[i + 1][j],
                             triangle[i + 1][j + 1]);
                triangle[i][j] += m;
                cout << i <<"\t" << j <<"\t" << m <<endl;
            }

        return triangle[0][0];
    }
};



int main() {
   vector<vector<int>> v2;
    v2.push_back({2});
    v2.push_back({3,4});
    v2.push_back({6,5,7});
    v2.push_back({4,1,8,3});

    Solution s;
    cout<< s.minimumTotal(v2)<<endl;

    return 0;

}

