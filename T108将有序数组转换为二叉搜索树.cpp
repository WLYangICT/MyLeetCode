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
这题确实简单，但是只是凭借直觉AC的，没有很确定的理论支撑
高度平衡题目已经解释了
二叉搜索树:左子树所有节点都比root小，右子树所有节点都比root大（便于搜索）

题目给的是升序排列的数组

所以第一个想到的就是，root应该是nums中间的数，这样左右才能平衡
那就会想到递归了吧，middle左边的数作为一个数组得到左子树，middle右边的数作为一个数组得到右子树
左子树肯定都比自己小，右子树肯定都比自己大
而且因为左右数目几乎一致，顶多差一个，而且都是升序排列
所以应该左右是平衡的
那么应该就符合题意了

递归就比较好写了
二叉树一定要用好递归！
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return nullptr;
        }
        else if(nums.size() == 1)
        {
            TreeNode* root = new TreeNode(nums[0]);
            return root;
        }
        else  //nums.size() > 1
        {
            //取出最中间的一个作为root，左右分开
            int middle = nums.size() / 2;
            vector<int> leftv, rightv;
            for(int i = 0; i < middle; i++)
            {
                leftv.push_back(nums[i]);
            }
            for(int i = middle+1; i < nums.size(); i++)
            {
                rightv.push_back(nums[i]);
            }
            TreeNode *left, *right;
            left = sortedArrayToBST(leftv);
            right = sortedArrayToBST(rightv);
            TreeNode* root = new TreeNode(nums[middle]);
            root->left = left;
            root->right = right;
            return root;
        }
    }
};