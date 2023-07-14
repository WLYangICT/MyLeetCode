class Solution {
public:
/*
其实这道题还是背包、完全平方数类型的：有两个变量，给定目标/预算求另一个变量的最大/最小

仍旧是要用二维数组OPT[i][j]代表最优解，并且分析其含义

再设置好边界数值，然后自底向上填充即可

但是但是！！！这题一定要注意，本题的-1代表无解，因为硬币可能凑不出amount，所以递归的方程需要判断的条件比较复杂
*/
    int coinChange(vector<int>& coins, int amount) {
        //二维数组OPT描述最优解结构：OPT[i][j]表示用下标范围1~i的硬币组成数额j的最小硬币数量
        int** OPT = new int* [coins.size() + 1];
        for(int i = 0; i <= coins.size(); i++)
        {
            OPT[i] = new int [amount + 1];
        }
        //二维数组初始化
        for(int i = 0; i <= amount; i++)
        {
            OPT[0][i] = -1;  //表示∞
            if(i % coins[0] == 0)
            {
                OPT[1][i] = i / coins[0];
            }
            else
            {
                OPT[1][i] = -1;
            }
        }
        for(int i = 0; i <= coins.size(); i++)
        {
            OPT[i][0] = 0;
        }
        //自底向上填充数组
        //自底向上填充数组
        for(int i = 2; i <= coins.size(); i++)
        {
            for(int j = 1; j <= amount; j++)
            {
                if(coins[i-1] > j)  //当前硬币超过amount，显然不能用
                {
                    if(OPT[i-1][j] == -1)  //同时剩下的硬币凑不出来，自然是-1
                    {
                        OPT[i][j] = -1;
                    }
                    else  //凑的出来
                    {
                        OPT[i][j] = OPT[i-1][j];
                    }
                }
                else
                {
                    if (OPT[i-1][j] == -1)  //不用该硬币就凑不出
                    {
                        if (OPT[i][j-coins[i-1]] == -1)  //使用该硬币，剩下的就凑不出
                        {
                            OPT[i][j] = -1;
                        }
                        else
                        {
                            OPT[i][j] = 1 + OPT[i][j-coins[i-1]];
                        }
                    }
                    else
                    {
                        if (OPT[i][j-coins[i-1]] == -1)  //使用该硬币，剩下的就凑不出
                        {
                            OPT[i][j] = OPT[i-1][j];
                        }
                        else
                        {
                            OPT[i][j] = min((1+OPT[i][j-coins[i-1]]), OPT[i-1][j]);
                        }
                    }
                }
            }
        }
        return OPT[coins.size()][amount];
    }
};