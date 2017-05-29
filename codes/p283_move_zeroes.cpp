#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <array>
#include <time.h>
#include <assert.h>
#include <stack>
#include <regex>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (int i= 0; i!=nums.size();i++){
            if (nums[i]!= 0) swap(nums[i], nums[pos++]);
        }
    }
};


int main()
{
    vector<int> v = {0,1,0,3,12};
     Solution().moveZeroes(v);
    for (auto item:v)
        cout << item << "\t";
    
    //cout << Solution().hammingDistance(100,101)<<endl;

    return 0;
}