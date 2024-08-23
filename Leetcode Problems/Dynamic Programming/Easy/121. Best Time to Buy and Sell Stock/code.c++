class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_day=-1;
        int buy=INT_MAX;
        int sell_day=-1;
        int profit=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<buy)
            {
                buy=prices[i];
                buy_day=i;
            }
            else if(prices[i]>prices[buy_day])
            {
                sell_day=i;
            }
            if(buy_day<sell_day)
            {
                profit=max(profit,prices[sell_day]-prices[buy_day]);
            }
        }
        return profit;
    }
};
