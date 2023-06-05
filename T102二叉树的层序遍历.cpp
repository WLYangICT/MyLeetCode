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
树的层序遍历实际上就是BFS，广度优先搜索
实际上用队列实现就很简单
但是比较难的地方在于要按层输出，而不是一次性输出全部节点

解决的办法就是一层一层处理，每次处理之前，先看看当前队列有多少节点
用一个for循环把这些节点一起解决了
然后接着就是下一层了
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr)
        {
            return res;
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        int nodes_num;  //每层的节点数目
        while(!nodes.empty())
        {
            vector<int> ans;
            nodes_num = nodes.size();  //节点数目
            for(int i = 0; i < nodes_num; i++)
            {
                TreeNode* p = nodes.front();
                ans.push_back(p->val);
                nodes.pop();
                if(p->left != nullptr)
                {
                    nodes.push(p->left);
                }
                if(p->right != nullptr)
                {
                    nodes.push(p->right);
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};