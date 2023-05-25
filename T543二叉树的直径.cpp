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
    int direct = 0;
    int maxDepth(TreeNode* root)
    {
        //给一棵树，判断最大深度
        int depth = 0;
        if(root == nullptr)
        {
            ;
        }
        else
        {
            depth = max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
        return depth;
    }

    //还是递归呀
    //关键在于任意路径都可以看作经过某一点的左子树的深度和右子树的深度之和
    int diameterOfBinaryTree(TreeNode* root) {
        //遍历整棵树，每个点看经过该点的最长路径，最长中的最长就是直径
        int direct = 0;
        if(root == nullptr)
        {
            ;
        }
        else
        {
            int left_direct = diameterOfBinaryTree(root->left);
            int right_direct = diameterOfBinaryTree(root->right);
            int mine_direct = maxDepth(root->left) + maxDepth(root->right);
            direct = max(left_direct, right_direct);
            direct = max(direct, mine_direct);
        }
        return direct;
    }
};