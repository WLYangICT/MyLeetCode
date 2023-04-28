class Solution {
public:
    /*
    使用除法的解决方案
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int mul = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            mul *= nums[i];
        }
        if(mul == 0)
        {
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] != 0)
                {
                    ans.push_back(0);
                }
                else
                {
                    int temp = 1;
                    for(int j = 0; j < nums.size(); j++)
                    {
                        if(j == i)
                        {
                            continue;
                        }
                        temp *= nums[j];
                    }
                    ans.push_back(temp);
                }
            }
        }
        else
        {
            for(int i = 0; i < nums.size(); i++)
            {
                ans.push_back(mul / nums[i]);
            }
        }
        return ans;
    }
    */

    /*
    使用左右乘积列表，类似于前缀和数组
    用一次O(n)的循环计算出每个元素左侧所有元素的乘积
    再用一次O(n)的循环计算出每个元素右侧所有元素的乘积
    再用一次O(n)的循环计算ans，（left*right）
    时空复杂度均为O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int* left = new int[nums.size()];
        int* right = new int[nums.size()];
        int left_mul = 1, right_mul = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            left[i] = left_mul;
            left_mul *= nums[i];
        }
        for(int i = nums.size()-1; i >= 0; i--)
        {
            right[i] = right_mul;
            right_mul *= nums[i];
        }
        int res;
        for(int i = 0; i < nums.size(); i++)
        {
            res = left[i] * right[i];
            ans.push_back(res);
        }
        return ans;
    }
    */

    //空间复杂度为O(1)的解法
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        //用ans存储原本left数组应该存储的数据
        int left_mul = 1, right_mul = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            ans.push_back(left_mul);
            left_mul *= nums[i];
        }
        //用原始数组存储原本right数组应该存储的数据
        int right_tmp;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            right_tmp = nums[i];
            nums[i] = right_mul;
            right_mul *= right_tmp;
        }
        //最后更新ans数组
        for(int i = 0; i < ans.size(); i++)
        {
            ans[i] *= nums[i];
        }
        return ans;
    }    
};