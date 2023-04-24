class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return nums[0];
        }
        else{
            vector<int> prefixSums(nums.size());  //前缀和数组
            int prefixSum = nums[0];
            prefixSums[0] = prefixSum;
            int minVal = nums[0];  //维护最小的前缀和数值
            int maxVal = nums[0];  //维护最大的子段和数值
            for(int i = 1; i < nums.size(); i++)
            {
                //计算前缀和
                prefixSum += nums[i];
                prefixSums[i] = prefixSum;
                if(minVal >= 0)
                {
                    //那最大的子段和就是自己的前缀和
                    int tmpMax = prefixSums[i];
                    if(tmpMax > maxVal)
                    {
                        maxVal = tmpMax;
                    }
                }
                else
                {
                    //有小的可以减
                    int tmpMax = prefixSums[i] - minVal;
                    if(tmpMax > maxVal)
                    {
                        maxVal = tmpMax;
                    }
                }
                //更新minVal
                if(prefixSums[i] < minVal)
                {
                    minVal = prefixSums[i];
                }
            }
            return maxVal;
        }
    }
};