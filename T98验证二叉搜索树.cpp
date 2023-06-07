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

/*
这道题一如既往尝试用递归解决
二叉搜索树要求左侧节点一定全小于当前节点，右侧节点一定全大于当前节点
并且左右子树都是二叉搜索树

所以很自然的想到，如果实现一个函数check，能做到给出根节点root，并求出当前树的最大最小值，同时判断是否为二叉搜索树的话
那么我们把左子树拿去check，判断左侧是不是二叉搜索树，并且得到左侧的最大值；
再把右子树拿去check，判断右侧是不是二叉搜索树，并且得到右侧的最小值；
那么就可以进行判断了。

以上的思路就是一个递归程序。

看了题解发现
其实用中序遍历二叉搜索树一定是递增序列，这个也可以拿来判断
*/

class Solution {
public:
    bool check(TreeNode* root, int& max, int& min)  //判断是不是二叉搜索树，并且返回
    {
        if(root == nullptr)
        {
            return true;
        }
        else
        {
            bool left_flag, right_flag;
            int left_max, left_min, right_max, right_min;
            if(root->left == nullptr)
            {
                left_flag = true;
                min = root->val;
            }
            else
            {
                left_flag = check(root->left, left_max, left_min);
                if(!left_flag)
                {
                    return false;
                }
                if(left_max >= root->val)
                {
                    return false;
                }
                min = left_min;
            }
            //能到这里说明左边一定是搜索树，且均小于root
            if(root->right == nullptr)
            {
                max = root->val;
                return true;
            }
            else
            {
                right_flag = check(root->right, right_max, right_min);
                if(right_flag && (right_min > root->val))
                {
                    //满足条件
                    max = right_max;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    bool isValidBST(TreeNode* root) {
        int max, min;
        return check(root, max, min);
    }
};