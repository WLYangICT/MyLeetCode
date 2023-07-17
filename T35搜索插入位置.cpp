class Solution {
public:
//就是暴力的二分法
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low < high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else
            {
                if(target > nums[mid])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        //最终跳出会是low == high
        if(nums[low] == target)
        {
            return low;
        }
        else if(nums[low] > target)
        {
            return low;
        }
        else
        {
            return (low + 1);
        }
    }
};