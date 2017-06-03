/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size()==0)
            return NULL;
        TreeNode *head = helper(nums,0,nums.size()-1);
        return head;
    }
    TreeNode* helper(vector<int> &nums,int left,int right){
        if (left > right)
            return NULL;
        int mid = (left+right)/2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = helper(nums,left,mid-1);
        node->right = helper(nums,mid+1,right);
        return node;
    }
};