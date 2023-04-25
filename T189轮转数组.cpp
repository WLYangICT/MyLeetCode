class Solution {
public:
    
    //暴力O(k*n)的时间复杂度，时间超限

    //翻转数组的方法，时间复杂度O(n)，空间复杂度O(1)
    //需要很强的观察力，实际上可以说是一种规律
    void reverse(vector<int>& nums, int begin, int end)
    {
        //将nums数组下标begin-end的部分翻转一下
        int temp;
        for(int i = begin; i <= (begin + (end - begin) / 2); i++)
        {
            temp = nums[i];
            nums[i] = nums[end - (i - begin)];
            nums[end - (i - begin)] = temp;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int times = k % nums.size();  //轮转次数
        if(times == 0)
        {
            return;
        }
        else{
            //先把整个数组翻转一下
            reverse(nums, 0, nums.size()-1);
            //翻转后的前times个元素翻转，剩下元素翻转
            reverse(nums, 0, times-1);
            reverse(nums, times, nums.size()-1);
        }
    }
    
    //以下两种方法是空间换时间的方法
    /*
    计算对应位置下标的方法，牺牲空间复杂度，时间复杂度O(n)
    void rotate(vector<int>& nums, int k) {
        int times = k % nums.size();  //轮转次数
        vector<int> tmp = nums;  //拷贝一个数组
        for(int i = 0; i< nums.size(); i++)
        {
            //直接计算对应的下标
            int index = (i + times) % (nums.size());
            nums[index] = tmp[i];
        }
    }
    */
    /*
    根据轮转次数确定开始的下标，然后轮一圈即可，时间复杂度O(n)
    void rotate(vector<int>& nums, int k) {
        int times = k % nums.size();  //轮转次数的等效值
        vector<int> tmp = nums;  //拷贝一个数组
        if(times == 0)
        {
            return;
        }
        else
        {
            int begin_index = nums.size() - times;
            for(int i = 0; i< nums.size(); i++)
            {
                //直接计算对应的下标
                int index = (begin_index + i) % nums.size();
                nums[i] = tmp[index];
            }
        }
    }
    */
};