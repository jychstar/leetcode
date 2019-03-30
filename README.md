My hometown: https://docs.google.com/presentation/d/1hEBnpBHatCZLrZu-Tiyt1odG2I9r9jpejNlAgN9hdC0/edit?usp=sharing

My LeetCode profile:  https://leetcode.com/jychstar/

solutions: <http://bookshadow.com/leetcode/>

https://www.geeksforgeeks.org/whats-new/

warald’s suggestion: [**communication skill** and coding skill are both important](https://www.linkedin.com/pulse/leetcode%E5%88%B7%E9%A2%98%E4%BA%94%E9%81%8D%E8%BF%98%E6%B2%A1offer%E4%B8%BE%E4%BE%8B%E6%B7%B1%E5%85%A5%E5%88%86%E6%9E%90%E4%B8%BA%E4%BB%80%E4%B9%88%E6%89%BE%E5%B7%A5%E4%BD%9C%E5%85%89%E5%88%B7%E9%A2%98%E6%B2%A1%E7%94%A8-xiaoning-warald)

刷题指南: https://segmentfault.com/a/1190000006059081

有趣的刷题: http://liangjiabin.com/allpost

牛顿迭代法求方根: http://www.2cto.com/kf/201206/137256.html

## cloud service comparison

Github: 1 GB, file limit of 100 MB (or 25MB via a browser)). 7 USD per month for 5 private repositories. 

google drive: 15GB: free, 100GB: 2 per month. Note: version control

drop box: 3G: free, 1TB: 8 per month. Note: version control

one drive: 5G:free, 100GB: 2 per month

icloud drive: 5GB: free. 50GB: 1 per month

## resources:

1. leetcode 151 solutions by category: https://github.com/soulmachine/leetcode
2. leetcode 468 solutions with comlexity list: https://github.com/kamyu104/LeetCode
3. leetcode c++ solutions: https://github.com/haoel/leetcode

## online coding

13 programming languages **except Java**:<http://codepad.org/>

online python: <https://tmp54.tmpnb.org/>

Mock interview: <https://www.pramp.com/>

run c++ online: <http://cpp.sh/>

online co-coding white board: <http://collabedit.com/>

## choose C++

Although Python is very easy to use, I would recommend using C++ to practice algorithm and data structure, because:

1. C++ is less packaged, so you get a chance to know more details
2. C++ is industrial standard. You foster a habit of declaring data type for input and output
3. C++ is much faster than Python.

For example. The 1st leetcode problem: twoSum. 

python code (62 ms):

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

c++ code (4 ms):

```c++
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int key = target - nums[i]; //
            if (m.find(key) != m.end())
                return {m[key], i};
            else
                m[nums[i]] = i;
        }
        return {-1,-1}; // in case none found
    }
};
```

If the header is not included, c++ code actually has the **similar lines of codes** as python, but is **way faster (9ms vs 62ms)**. When hardware doesn't have unlimited speed, a significant boost from language/algorithm is worth the effort. 

