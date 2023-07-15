class Solution {
public:
    /*
    暴力的动态规划思想：
    定义最优解的结构：一维数组max_pro[i]表示以nums[i]结尾的最大连乘子数组
    最优解ans即max_pro数组的最大值
    但是在状态转移的过程暴力了
    可能简单的想法是max_pro[i] = max(nums[i], nums[i]*max_pro[i-1])
    但是遇到的问题是：
        比如nums[i]是负数，max_pro[i-1]是正数，那么上述状态转移会得到max_pro[i] = nums[i]
        但是nums[i-1]可以是某个值为负的连乘子数组的结尾
        那么显然max_pro[i] != nums[i]
    
    暴力的想法是，对于每个i，我们从0~i-1都试一遍，取最大值即可

    时间复杂度O(n^2)，实际上就是暴力地遍历了所有的子序列

    int maxProduct(vector<int>& nums) {
        int* max_pro = new int [nums.size()];
        max_pro[0] = nums[0];
        int ans = max_pro[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int tmp_pro = nums[i];
            int tmp_max = nums[i];
            for(int j = i-1; j >= 0; j--)
            {
                tmp_pro = tmp_pro * nums[j];
                tmp_max = max(tmp_max, tmp_pro);
            }
            max_pro[i] = tmp_max;
            ans = max(ans, max_pro[i]);
        }
        return ans;
    }*/

    /*
    1、定义最优解的结构：
        一维数组max_pro[i]表示以nums[i]结尾的最大连乘子数组
        最优解ans即max_pro数组的最大值
    2、初始化和边界确定：
        max_pro[0] = nums[0]
    3、但是之前采用暴力的原因在于正负数导致了状态转移的不确定性：
        那我们不妨考虑分类讨论正负值：
            如果nums[i] >= 0:
                我们希望nums[i-1]之前是一个连乘为正的子序列且越大越好
            如果nums[i] < 0:
                我们希望nums[i-1]之前是一个连乘为负的子序列且越小越好
    这样的时间复杂度就是O(n)，大大缩短了时间成本
    关键在于利用了之前的信息，上一个暴力方法完全没利用前面的信息
    而最长递增子序列主要是不得不遍历全部信息
    */
    int maxProduct(vector<int>& nums) {
        int* max_pro = new int [nums.size()];
        int* min_pro = new int [nums.size()];
        max_pro[0] = nums[0];
        min_pro[0] = nums[0];
        int ans = max_pro[0];
        for(int i = 1; i < nums.size(); i++)
        {
            max_pro[i] = max(max(nums[i], nums[i]*max_pro[i-1]), nums[i]*min_pro[i-1]);
            min_pro[i] = min(min(nums[i], nums[i]*max_pro[i-1]), nums[i]*min_pro[i-1]);
            ans = max(ans, max_pro[i]);
        }
        return ans;
    }
};