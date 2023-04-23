/*
又是一道看题解写出来的题目

其实最开始想到的是双指针解法，但是后来注意到数组里面可能存在负数，双指针失败

接着就还是先看看用暴力解，那就是遍历所有子串O(n^2)，对于每个子串再计算累加和O(n)
也就是最终复杂度是O(n^3)，显然要超时

子串的累加很容易想到前缀和数组，先算好前缀和数组，然后再遍历所有子串
复杂度从O(^3) -> O(n^2)，但是还是不够，继续超时

最后是看到了一个题解写出了最终AC的答案：
    实际上我们是看前缀和数组有几个子段（尾 - 头）为k
    可以利用map实现
    每次我们计算nums[i]对应的前缀和prefixSum时，我们可以看看prefixSum - k对应的前缀和数值是否出现过
    如果出现过，k ~ i就是满足题目条件的一个子串，ans += 出现次数
    计算之后，prefixSum数值的出现次数+1
    最终返回ans
    实际上这么做时间复杂度只有O(n)
    最终AC
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;  //前缀和
        int ans = 0;
        map<int, int> prefixSums;
        prefixSums.insert({0, 1});
        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            if(prefixSums[prefixSum - k])
            {
                ans += prefixSums[prefixSum - k];
            }
            prefixSums[prefixSum]++;
        }
        return ans;
    }
};