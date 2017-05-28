#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int> nums) {

        sort(nums.begin(),nums.end());

        vector<vector<int>> res;
        if (nums.size()<3)
            return res;

        auto last = nums.end();
        // go through i, find matched (left,right) pair
        for (auto i = nums.begin(); i<last-2; ++i){
            if ((i!=nums.begin() && *i==*(i-1))) continue;
            auto left = i+1, right = last-1;
            while (left <right){
                int sum = *i + *left+ *right;
                if ( sum == 0){
                    res.push_back({*i,*left,*right});
                    left++;
                    right--;
                    while ((left< right) && *left  == * (left-1) ) left++;
                    while ((left< right) && *right == *(right+1) ) right--;
                }

                else if (sum <0)
                    left++;
                else
                    right--;
            } //end while
        }// end for
        return res;
    }
};


const int SIZE = 7;

int main()
{
    vector<int> v ={-1,0,1,2,-1,-4,-4,2};
    Solution a;
    auto v2 = a.threeSum(v);

    for (auto v1:v2){
        for (auto item:v1)
            cout << item <<"\t";
        cout<<endl;
    }



    return 0;
}

