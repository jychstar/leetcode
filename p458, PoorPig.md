## Problem

https://leetcode.com/problems/poor-pigs/

There are 1000 buckets, one and only one of them contains poison, the rest are filled with water. They all look the same. If a pig drinks that poison it will die within 15 minutes. What is the minimum amount of pigs you need to figure out which bucket contains the poison within one hour.

Answer this question, and write an algorithm for the follow-up general case.

**Follow-up:**

If there are n buckets and a pig drinking poison will die within m minutes, how many pigs (x) you need to figure out the "poison" bucket within p minutes? There is exact one bucket with poison.

## Thinking process

What a joy to think about this brainteaser! I didn't know where to start until I saw [ifyouseewendy](https://discuss.leetcode.com/user/ifyouseewendy)'s explanation. The key point is you can use multiple pigs to drink a same bucket and use a same pig to drink multiple buckets. This is more an **encoding** problem than a coding problem.

The previous two posts have made intuitive graphs to illustrate the ideas. However, I still find some confusing sentences. Here, I would like to share my understanding. 

Suppose we have two pigs A and B for this thought experiment, then we can use a two-digit numeral system AB to label as many buckets as possible. The value of each digit means:

| value | meaning                                  |
| :---: | ---------------------------------------- |
|   0   | a pig won't drink this bucket, it always survives from this bucket |
|   1   | a pig drinks this bucket in the 1st round, it may die or survive |
|   2   | a pig drinks this bucket in the 2nd round, it may die or survive |

So for the first round, we can only test 4 buckets labelled as 00,01,10,11. If the result of the 1st round  is only about A and A dies, then we can infer bucket 10 or 11 may contain poison. If we further know B survives the first round, then we are sure the bucket 10 is the culprit. 

But if we add the 2nd round of test, what happens? 5 more buckets can be labelled, which are 02,12, 20,21,22. Note that buckets 12 and 21 partially involve in the 1st round test, in which A drinks 10,11,12 and B drinks 01,11, 21. If we get the information that A dies in the 1st test, we can infer that 10,11,12 are the suspects. If we additional know B dies in the first round, then bucket 11 is poisonous and we don't need to carry the 2nd round test. But if B survives the 1st round, advance to the 2nd round and still survives, then we know all the buckest B have drank, i.e., A1 and A2, are safe. So in the case we know A dies in the 1st round, then we can infer the bucket 10 is poisonous. 

Why a 2-round test can identify more than twice that in 1-round test (9 vs 4)? Because the 2-round pigs can also peek into the "future" (12,21) in their 1st round. In a larger scale, the pigs that are planned in many-round tests will drink more in the 1st round, which allow them to gain much more information than the pigs stuck in fewer-round tests. 

## Codes

n pigs in p-round tests can identify N=(p+1)^n buckets. so the required pigs are $log_{p+1}{N}$

```python
class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        """
        :type buckets: int
        :type minutesToDie: int
        :type minutesToTest: int
        :rtype: int
        """
        time = minutesToTest/minutesToDie
        import math
        return int(math.ceil(math.log(buckets,time+1)))
```

## Afterthought



> You can fool all the people some of the time and some of the people all the time, but you cannot fool all the people all the time.

Because a single lie is surely digged out by many peoples and many tests. However, in reality, there are more biases and systematica errors, rather than black/white, true/false "poisons".

Another life hack advice is, to find your "true love" in life, you will get a better chance if you try "more buckets" in your earlier life stages. You never know if you don't try. "A peek into the future"  sounds too good to be true, but it's possible. 