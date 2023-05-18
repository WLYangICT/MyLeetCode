/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //感觉还是递归
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
        {
            return nullptr;
        }
        invertTree(root->left);  //左边翻转
        invertTree(root->right);  //右边翻转
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};