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
    /*递归解法，比较简单*/
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* p = root;
        if(p == nullptr)
        {
            return res;
        }
        else
        {
            vector<int> left = inorderTraversal(p->left);
            for(int i = 0; i < left.size(); i++)
            {
                res.push_back(left[i]);
            }
            res.push_back(p->val);
            vector<int> right = inorderTraversal(p->right);
            for(int i = 0; i < right.size(); i++)
            {
                res.push_back(right[i]);
            }
        }
        return res;
    }
};