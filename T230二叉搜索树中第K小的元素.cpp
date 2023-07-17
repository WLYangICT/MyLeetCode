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
    void transform(TreeNode* root, vector<int>& arr)
    {
        if(root == nullptr)
        {
            return;
        }
        else
        {
            transform(root->left, arr);
            arr.push_back(root->val);
            transform(root->right, arr);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        //直接中序遍历就会得到递增的数组，简单递归
        vector<int> arr;
        transform(root, arr);
        int ans = arr[k-1];
        return ans;
    }
};