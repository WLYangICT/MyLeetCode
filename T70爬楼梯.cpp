class Solution {
public:
    /*
    其实就是斐波那契数列，到达第i个台阶可以由i-1跨一步或者i-2跨两步到达
    自下而上地写就行
    */
    int climbStairs(int n) {
        int* method_nums = new int[n + 1];
        method_nums[1] = 1;
        method_nums[0] = 1;
        for(int i = 2;i <= n;i++)
        {
            method_nums[i] = method_nums[i-1] + method_nums[i-2];
        }
        return method_nums[n];
    }
};