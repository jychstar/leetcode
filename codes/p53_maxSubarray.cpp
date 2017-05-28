#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, cur = 0;
        for (int num:nums){
            //cur = max(cur+num,num);
            cur = cur>0? cur+num : num;
            res = max(res,cur);
        }
        return res;
    }
};


int main() {
   vector<int> v={-2,1,-3,4,-1,2,1,-5,4};

    cout<< Solution().maxSubArray(v) <<endl;

    return 0;

}

