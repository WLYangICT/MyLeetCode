class Solution {
public:
/*
这道题还是非常奇妙的。
在矩阵当中搜索某个元素
1、暴力查找，最简单最慢的方法 O(m * n)
2、逐行二分：
    因为每一行是有序的数组，所以在每一行当中二分一定能解决问题
    时间复杂度O(m * logn)
3、从右上角开始蛇形搜索：
    方法1完全没有利用矩阵的特性；方法2只利用了矩阵在行上升序的特性；
    方法3是综合利用了行升序和列升序的特性。
    我们以题目为例
     1  4  7 11 15
     2  5  8 12 19
     3  6  9 16 22
    10 13 14 17 24
    18 21 23 26 30
    注意到左上角的15有个特性，那就是同一行左边所有数字比它小，同一列下面所有数字比它大
    此时row = 0， col = 4， target = 5
    首先target < 15
    所以target一定不在15所在列下方，那一列都可以删掉
     1  4  7 11
     2  5  8 12
     3  6  9 16
    10 13 14 17
    18 21 23 26
    row = 0, col = 3
    target < 11，继续删列
     1  4  7
     2  5  8
     3  6  9
    10 13 14
    18 21 23
    target < 7， 继续删列
     1  4
     2  5
     3  6
    10 13
    18 21
    target > 4，所以target一定不在第一行，删行
     2  5
     3  6
    10 13
    18 21
    target = 5，找到了

    就这样从右上角开始蛇形，一次排除一行/列
    时间复杂度O(m + n)
*/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //从左上角开始
        int row = 0, col = matrix[0].size()-1;
        while(row < matrix.size() && col >= 0)
        {
            if(matrix[row][col] == target)
            {
                return true;
            }
            if(matrix[row][col] < target)
            {
                row += 1;
            }
            else  //matrix[row][col] > target
            {
                col -= 1;
            }
        }
        return false;
    }
};