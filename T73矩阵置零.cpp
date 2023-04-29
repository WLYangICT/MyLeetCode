/*
感觉这题也很简单，我甚至一开始没想O(mn)空间复杂度的方案
直接就是用两个集合（rows、cols）表示要置零的行列
一次遍历矩阵得到这两个集合的内容
然后分别置零即可
时间复杂度O(mn)还是很不错的，空间复杂度比较差
看了题解，那个标记变量的方法确实不错，O(1)的空间复杂度还是很猛的
*/
class Solution {
public:
/*
标记集合方法
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows, cols;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        set<int>::iterator it;
        for (it = rows.begin(); it != rows.end(); it++)
        {
            for(int j = 0; j < matrix[*it].size(); j++)
            {
                matrix[*it][j] = 0;
            }
        }
        for (it = cols.begin(); it != cols.end(); it++)
        {
            for(int j = 0; j < matrix.size(); j++)
            {
                matrix[j][*it] = 0;
            }
        }
    }
*/
    //标记变量方法，空间复杂度O(1)，一定要注意第一行和第一列的处理，很容易出错
    void setZeroes(vector<vector<int>>& matrix) {
        bool flag_row = false, flag_col = false;
        //先获得标记变量的取值
        //先看第一列
        for(int i = 0; i < matrix.size(); i++)
        {
            if(!matrix[i][0])
            {
                flag_col = true;
                break;
            }
        }
        //再看行
        for(int i = 0; i < matrix[0].size(); i++)
        {
            if(!matrix[0][i])
            {
                flag_row = true;
                break;
            }
        }
        //遍历矩阵，修改第一行和第一列的数值
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(!matrix[i][j])
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //根据第一行和第一列的值修改矩阵，注意第一行第一列不能动
        //看第一行
        for(int i = 1; i < matrix[0].size(); i++)
        {
            if(!matrix[0][i])
            {
                for(int j = 0; j < matrix.size(); j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        //看第一列
        for(int i = 1; i < matrix.size(); i++)
        {
            if(!matrix[i][0])
            {
                for(int j = 0; j < matrix[i].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        //再根据标记变量的值修改第一行和第一列
        if(flag_row)
        {
            //第一行本身有0，全置0
            for(int i = 0; i < matrix[0].size(); i++)
            {
                matrix[0][i] = 0;
            }
        }
        if(flag_col)
        {
            //第一列本身有0，全置0
            for(int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};