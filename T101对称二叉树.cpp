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
    //判断两棵树是否相等
    bool ifequal(TreeNode* a, TreeNode* b)
    {
        if(a == nullptr && b == nullptr)
        {
            return true;
        }
        else if((a == nullptr && b != nullptr) || (a != nullptr && b == nullptr))
        {
            return false;
        }
        else  //都不空
        {
            TreeNode *aleft = a->left, *bleft = b->left, *aright = a->right, *bright = b->right;
            if(ifequal(aleft, bleft) && ifequal(aright, bright) && (a->val == b->val))
            {
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }

    //翻转二叉树
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

    bool isSymmetric(TreeNode* root) {
        //一定会有root节点
        //把右边的树翻转一下
        invertTree(root->right);
        //如果两棵树一样，就true，否则false
        if(ifequal(root->left, root->right))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};