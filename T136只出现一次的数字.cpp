class Solution {
public:
/*
这道题虽然是一道简单题，但是我觉得一点都不简单，靠自己是真想不出来
线性时间复杂度和O(1)的空间复杂度要求太高了
也就是说不能用额外的空间，还要一次遍历完成

补充一下异或的知识（没想到异或都忘了）
异或^：
    异或指的是两个数a b：
        a == b -> a ^ b == 0
        a != b -> a ^ b == 1
    并且有两个定理：
        1、0 ^ x = x:
            即任何数与0的异或结果是本身
        2、a ^ b ^ a = a ^ a ^ b

所以对于本道题，我们把所有数字异或起来，通过交换律，把相同的数字放到相邻位置异或
最终结果就是 0 ^ target = target
也就得到最终结果了
*/
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};