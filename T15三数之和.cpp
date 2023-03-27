//怎么也没想到这是一题双指针的题目
//排序+双指针的思路可以解决问题
//但是去重需要考虑清楚怎么做

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        一定要注意这里的不能出现重复的三元组，不是一开始给数组去个重
        比如 -1 -1 2
        元素有重复，但是三元组是唯一的，所以满足
        */
        //开始计算
        vector<vector<int>> ans;
        //暴力n^3指定超时
        //把nums排个序
        sort(nums.begin(), nums.end());
        //逐个判断，和后面的元素相加是否为0
        //注意有两个判断重复的地方，一个是i移动的时候，一个是left、right移动的时候
        for (int i = 0; i < nums.size()-2; i++)
        {
            if (nums[i] > 0)  //显然后面都不可能了
            {
                return ans;
            }
            else
            {
                int left = i + 1, right = nums.size() - 1;
                while (left < right)
                {
                    if ((nums[i] + nums[left] + nums[right]) > 0)
                    {
                        right--;
                    }
                    else if ((nums[i] + nums[left] + nums[right]) < 0)
                    {
                        left++;
                    }
                    else
                    {
                        //等于0，需要好好讨论了
                        ans.push_back({nums[i], nums[left], nums[right]});
                        //怎么移动指针很重要
                        left++;
                        right--;
                        //问题在于，有可能left、right对应的元素没有变
                        while (left < right && nums[left] == nums[left-1])
                        {
                            left++;
                        }
                        //这时候其实已经避免重复了，但是right如果相同值肯定也不满足条件，也可以跳过相同值
                        while (left < right && nums[right] == nums[right+1])
                        {
                            right--;
                        }
                    }
                }
            }
            //已经要下一个了，但是如果下一个i和当前一样，那就跳过
            while ((i < nums.size()-2) && (nums[i+1] == nums[i]))
            {
                i++;
            } 
        }
        return ans;
    }
};