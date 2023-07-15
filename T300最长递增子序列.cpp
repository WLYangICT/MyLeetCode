class Solution {
public:
/*
又是一道DP+双指针的题

1、定义最优解的结构：
    一维数组res[i]: 代表以nums[i]为结尾的最长递增子序列长度
    注意：ans是res数组的最大值，而不是res[n]，这一点和之前是不一样的

2、初始化、边界条件:
    res[0] = 1

3、状态转移：
    对于一个nums[i]，我们需要用一个j从i-1到0搜索，也就是看看前面有没有一个最长递增子序列能加上nums[i]
    如果nums[j] >= nums[i]，显然无法带上nums[i]构成严格递增子序列
    如果nums[j] < nums[i]，那么j结尾的最长递增子序列加上nums[i]就是一个长度为res[j]+1的递增子序列
    我们只需要在所有备选答案当中找到最大值记录下来即可

时间复杂度O(n^2)：一轮搜索&每次都向前搜索一遍

是有时间复杂度为O(nlogn)的解的：
纸牌游戏和线段树
*/
    int lengthOfLIS(vector<int>& nums) {
        int* res = new int [nums.size()];  //res[i]表示以nums[i]结尾的最长递增子序列长度，解的结构
        //边界设定&初始化
        res[0] = 1;
        //自下而上的状态转移
        int tmp_max, max_len = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            tmp_max = 0;
            for(int j = i-1; j >= 0; j--)
            {
                if(nums[j] >= nums[i])
                {
                    continue;  
                }
                else
                {
                    tmp_max = max(tmp_max, res[j]);
                }
            }
            tmp_max += 1;  //加上本身就是+1
            res[i] = tmp_max;
            max_len = max(max_len, tmp_max);
        }
        return max_len;
    }
};