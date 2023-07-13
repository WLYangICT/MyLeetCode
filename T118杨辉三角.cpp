class Solution {
public:
    /*
    和斐波那契数列类似，自下而上计算即可
    不需要递归
    属于最简单的一类dp
    */
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        //vector<int>* arrs = new vector<int> [numRows];
        for(int i = 1; i <= numRows; i++)
        {
            //第i行有i个元素
            vector<int> tmp_res;
            for(int j = 0; j < i; j++)
            {
                if(j == 0 || j == (i-1))
                {
                    tmp_res.push_back(1);
                }
                else
                {
                    tmp_res.push_back(res[i-2][j-1] + res[i-2][j]);
                }
            }
            res.push_back(tmp_res);
        }
        return res;
    }
};