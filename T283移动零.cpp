class Solution {
public:
//双指针
    void moveZeroes(vector<int>& nums) {
        int tail = nums.size() - 1;  //下一个零元素应该放置的位子，初始化为最后一个
        int head = 0;  //开始查找的位置
        for(int i = head; i <= tail; i++)
        {
            if(nums[i] == 0)
            {
                //就开始往后冒泡到tail
                for(int j = i + 1; j <= tail; j++)
                {
                    nums[j-1] = nums[j];
                }
                nums[tail] = 0;
                tail--;
                i--;
            }
        }
    }
};