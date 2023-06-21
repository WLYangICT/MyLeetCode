class Solution {
public:
/*
暂时先不写题解，没靠自己写出来
*/
    int jump(vector<int>& nums) {
        int jumpTimes = 0;
        int start = 0;
        int end = 1;
        while(end < nums.size())
        {
            int farest = 0;
            for(int i = start; i < end; i++)
            {
                farest = max(farest, i+nums[i]);
            }
            start = end;
            end = farest + 1;
            jumpTimes++;
        }
        return jumpTimes;
    }
};