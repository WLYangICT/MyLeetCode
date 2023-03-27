class Solution {
public:

    int maxArea(vector<int>& height) {
        //经典的双指针问题
        int head = 0, tail = height.size() - 1;
        int ans = 0;
        while(head != tail)
        {
            int tmp;
            if(height[head] <= height[tail])
            {
                tmp = height[head] * (tail - head);
                head++;
            }
            else
            {
                tmp = height[tail] * (tail - head);
                tail--;
            }
            if(tmp > ans)
            {
                ans = tmp;
            }
        }
        return ans;
    }
};