class Solution {
public:
    int rob(vector<int>& nums) {
        int cur = 0, pre = 0, tmp;
        for (int x:nums){
            tmp = cur;
            cur = pre + x;
            pre = max (tmp, pre);
        }
        return max (cur,pre);
    }
};