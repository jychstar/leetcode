#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> m;
        vector<int> res = {-1, -1};
        for (int i = 0; i < nums.size(); i++) {
            int key = target - nums[i];
            if (m.find(key) != m.end()) {
                res = {m[key], i};
                return res;
            } else {
                m[nums[i]] = i;
            }
        }
        return res;
    }
};

int main() {

    Solution a;
    vector<int> input = {1, 2, 3, 4};

    for (int i: a.twoSum(input, 8)) {
        cout << i << "\t";
    }

    return 0;
}