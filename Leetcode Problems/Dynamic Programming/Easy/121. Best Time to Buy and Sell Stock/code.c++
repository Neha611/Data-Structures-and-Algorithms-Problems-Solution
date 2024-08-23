/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let buy_day=-1;
    let buy=Number.MAX_VALUE;
    let sell_day=-1;
    let profit=0;
    for(let i=0;i<prices.length;i++)
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
            profit=Math.max(profit,prices[sell_day]-prices[buy_day]);
        }
    }
    return profit;
};
