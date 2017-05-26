I decide to practice leetcode with C++, instead of Python. 

## python vs c++: speed

The very first leetcode problem: twoSum

python code:

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic={}
        for i in range(len(nums)):
            key = target - nums[i]
            if key in dic:
                return [dic[key], i]
            else:
                dic[nums[i]] = i
        return [-1, -1]
```

c++ code:

```c++
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
```

If the header is not included, c++ code actually has the similar lines of codes as python, but is way faster (9ms vs 62ms). When hardware doesn't have unlimited speed, a significant boost from algorithm is worth the effort. 

## resources:

1. leetcode 151 solutions by category: https://github.com/soulmachine/leetcode
2. leetcode 468 solutions with comlexity list: https://github.com/kamyu104/LeetCode
3. leetcode c++ solutions: https://github.com/haoel/leetcode

# leetcode
