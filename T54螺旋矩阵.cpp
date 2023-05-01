/*
按照正常思路模拟即可，没什么难的
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  //四个方向轮流
        //先0, 1 -> 1, 0 -> 0, -1 -> -1, 0
        int dir_flag = 0;  //开始的方向
        int** fmat = new int* [matrix.size()];
        for(int i = 0; i < matrix.size(); i++)
        {
            fmat[i] = new int [matrix[0].size()];
            for(int j = 0; j < matrix[0].size(); j++)
            {
                fmat[i][j] = 0;  //标识是否遍历过
            }
        }
        int x = 0, y = 0;  //初始位置
        vector<int> ans;
        while(1)
        {
            if(fmat[x][y])
            {
                //如果初始就访问过了就结束了
                break;
            }
            else{
                //没有访问过，先加入ans
                ans.push_back(matrix[x][y]);
                fmat[x][y] = 1;  //标识已经访问过
                //考虑挪动
                //按照当前方向
                int dx, dy;
                switch (dir_flag)
                {
                    case 0:
                        dx = 0;
                        dy = 1;
                        break;
                    case 1:
                        dx = 1;
                        dy = 0;
                        break;
                    case 2:
                        dx = 0;
                        dy = -1;
                        break;
                    case 3:
                        dx = -1;
                        dy = 0;
                        break;
                }
                int mx = x + dx, my = y + dy;  //代表可能移动的结果
                if((mx < 0 || mx >= matrix.size() || my < 0 || my >= matrix[0].size()) || fmat[mx][my])
                {
                    //如果超出边界或者已经访问过了，就要改方向
                    dir_flag += 1;
                    dir_flag = dir_flag % 4;
                    switch (dir_flag)
                    {
                        case 0:
                            dx = 0;
                            dy = 1;
                            break;
                        case 1:
                            dx = 1;
                            dy = 0;
                            break;
                        case 2:
                            dx = 0;
                            dy = -1;
                            break;
                        case 3:
                            dx = -1;
                            dy = 0;
                            break;
                    }
                    x += dx;
                    y += dy;
                    //改完方向也可能超出边界
                    if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
                    {
                        break;
                    }
                }
                else
                {
                    //继续按照这个方向
                    x = mx;
                    y = my;
                }
            }
        }
        return ans;
    }
};