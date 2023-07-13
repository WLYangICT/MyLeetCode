class Solution {
public:
/*
这道题完全就是背包问题的变式：
    其中数字n就相当于背包的容量
    使用的数字个数就相当于价值，只不过是价值最小化

这种两个变量都会变化的dp问题需要使用二维数组进行存储
OPT[i][j]表示，某个数大小为j，用0~i范围内数字的平方进行组合，得到该数字的最小数字数量
这就是最优解的结构分析，最优解是OPT[(int)sqrt(n)][n]

接下来就是实现递归或者说状态转换：
    如果i^2 > j:
        OPT[i][j] = OPT[i-1][j]
    如果i^2 <= j:
        OPT[i][j] = min((1+OPT[i][j-i^2]), (OPT[i-1][j])
        前者代表使用了i，后者代表没使用i，选择数目更小的即可

再解下来就是初始化了，需要初始化OPT[0][j]、OPT[1][j]、OPT[i][0]

最后逐行逐列计算，输出OPT[(int)sqrt(n)][n]即可
*/
    int numSquares(int n) {
        //创建二维数组（备忘录）
        int max_sqrt = (int)sqrt(n);
        int** OPT = new int* [max_sqrt + 1];
        for (int i = 0; i <= max_sqrt; i++)
        {
            OPT[i] = new int [n + 1];
        }
        //部分数值初始化，即边界设置
        for (int i = 0; i <=n ; i++)
        {
            OPT[0][i] = 1e5;  //不可能用0组成某个正整数
        }
        for (int i = 0; i <= max_sqrt; i++)
        {
            OPT[i][0] = 0;  //只要n是0，使用数字就是0
        }
        for (int i = 0; i <= n; i++)
        {
            OPT[1][i] = i;
        }
        //开始自底向上计算
        for (int i = 2; i <= max_sqrt; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(i > (int)sqrt(j))
                {
                    //肯定用不了i
                    OPT[i][j] = OPT[i-1][j];
                }
                else
                {
                    OPT[i][j] = min((1 + OPT[i][j-i*i]), OPT[i-1][j]);
                }
            }
        }
        return OPT[max_sqrt][n];    
    }
};