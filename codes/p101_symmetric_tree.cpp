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
    bool isMirror(TreeNode* left, TreeNode* right){
        if (!left && !right)
            return true;
        else if (left && right)
            return (left->val==right->val  && isMirror(left->right,right->left) && isMirror(left->left, right->right));
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        else 
            return isMirror(root->left,root->right);
    }
};