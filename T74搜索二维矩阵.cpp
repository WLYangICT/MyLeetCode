class Solution {
public:
/*
我们知道矩阵是一个升序的矩阵
最暴力的想法是直接把矩阵每一行首尾连接，直接变成一个一维数组，然后二分，但是这种方法太low太慢了

利用矩阵的升序特性，其实我们可以通过和每一行的第一个数组进行比较，来判断target是不是在那一行以后:
    target == matrix[i][0]  不用说，直接true
    target > matrix[i][0]  target一定在第i行以后，不一定是第i行，但是我们可以先记录是第i行
    target < matrix[i][0]  target一定不会在第i行以后，所以可以停止了
最后记录的那一行，target至少在那个范围内

如果确定了在某一行，就直接在里面二分就行

所以时间复杂度是O(m + logn)
还是很快的
*/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int in_row = -1;  //记录target应该在哪一行，-1代表不存在
        for(int i = 0; i < matrix.size(); i++)
        {
            if(matrix[i][0] == target)
            {
                return true;  //如果直接找到了最好
            }
            else if(matrix[i][0] < target)
            {
                in_row = i;  //至少在某一行
            }
            else
            {
                //一定不会在之后的行里了
                break;
            }
        }
        if(in_row == -1)
        {
            return false;
        }
        //接下来就在那一行进行二分查找就行
        int low = 0, high= matrix[in_row].size()-1, mid;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(matrix[in_row][mid] == target)
            {
                return true;
            } 
            else if(matrix[in_row][mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};