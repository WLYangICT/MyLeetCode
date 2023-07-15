class Solution {
public:
/*
其实这道题就是背包问题的变式
关键点在于：在数组内找到数字能够组成sum / 2，而且是恰好等于
所以就变成了背包问题
*/
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if((nums.size() == 1) || (sum % 2 == 1))  
        {
            //如果数组只有一个元素或者数组之和为奇数，显然不可能划分为两个元素和相等的子集
            return false;
        }
        //整道题最为关键的一步：如果能分割成两个元素和相等的子集，那么每个子集的和必然是总体和的一半
        //从而转换为类背包问题：能否从集合当中找到和恰好为sum/2的子集？
        int target = sum / 2;
        //定义最优解的结构：OPT[i][j]表示能否用1~i的元素恰好组成j，答案是OPT[n][sum/2]
        bool** OPT = new bool* [nums.size() + 1];
        for(int i = 0; i <= nums.size(); i++)
        {
            OPT[i] = new bool [target + 1];
        }
        //初始化和边界确定
        for(int i = 0; i <= target; i++)
        {
            OPT[0][i] = 0;  //不用任何元素显然是不行的
            //只用一个元素行不行直接看是否相等
            if(nums[0] == i)  //i=第一个元素
            {
                OPT[1][i] = 1;
            }
            else
            {
                OPT[1][i] = 0;
            }
        }
        for(int i = 0; i <= nums.size(); i++)
        {
            OPT[i][0] = 1;  //目标是0显然是可以的
        }
        //自下而上填充即可
        for(int i = 2; i <= nums.size(); i++)
        {
            for(int j = 1; j <= target; j++)
            {
                if(nums[i-1] > j)
                {
                    OPT[i][j] = OPT[i-1][j];
                }
                else
                {
                    OPT[i][j] = (OPT[i-1][j] || OPT[i-1][j-nums[i-1]]);
                }
            }
        }
        return OPT[nums.size()][target];
    }
};