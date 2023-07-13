class Solution {
public:
    int rob(vector<int>& nums) {
        int* best_value = new int[nums.size() + 1];  // best_value[i]表示1-i户的最大价值策略
        best_value[0] = 0;
        best_value[1] = nums[0];
        for(int i = 2; i <= nums.size(); i++)
        {
            best_value[i] = max(best_value[i-1], nums[i-1]+best_value[i-2]);
            //偷了第i户就是第i户的价值+隔一户1~i-2户的最大价值
            //没偷第i户最大值等于前i~1户最大值
        }
        return best_value[nums.size()];
    }
};