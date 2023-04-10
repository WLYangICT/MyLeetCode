//DFS递归
//终止条件left > right || (left == 0 && right == 0)
class Solution {
public:
    vector<string> ans;

    void dfs(string cur_s, int left, int right){
        if(left == 0 && right == 0){
            ans.push_back(cur_s);
            return;
        }
        if(left > right){
            return;
        }
        if(left > 0){
            dfs(cur_s+'(', left-1, right);
        }
        if(right > 0){
            dfs(cur_s+')', left, right-1);
        }
    }

    vector<string> generateParenthesis(int n) {
        string cur_s = "";
        int left = n, right = n;
        dfs(cur_s, left, right);
        return ans;
    }
};