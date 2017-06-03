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
    void searchBT(TreeNode* root, string path, vector<string> &res){
        if (!root->left && !root->right)
            res.push_back(path + to_string(root->val));
        if (root->left)
            searchBT(root->left,path + to_string(root->val) +"->", res);
        if (root->right)
            searchBT(root->right,path + to_string(root->val) +"->", res);   
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root)
            searchBT(root, "",res);
        return res;
    }
};