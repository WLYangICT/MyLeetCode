class Solution {
public:
    //暴力O(n^2会时间超限)
    /*
    贪心算法，遇到更低的点就想如果我在这时候买入就好了，但是很可能不会有前面的高值了，
    因此在更新前，记录一下找到的最大利润
    此后，遇到更高的price就更新sell的价格，寻找最高点
    遇到比buy更低的price就降低buy（仍需记录profit）
    */
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
        {
            return 0;
        }
        int maxPro = 0;
        int buy = prices[0];
        int sell = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < buy)
            {
                int profit = sell - buy;
                if(profit > maxPro)
                {
                    maxPro = profit;
                }
                sell = prices[i];
                buy = prices[i];
            }
            if(prices[i] > sell)
            {
                sell = prices[i];
            }
        }
        maxPro = max(maxPro, (sell - buy));
        return maxPro;
    }
};