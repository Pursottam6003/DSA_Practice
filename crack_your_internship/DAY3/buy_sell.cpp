// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        // we need to find the minimum buy and coorespoding maximum sell 

        // initialsize the buy variable and sell variable to 0
        int buy = prices[0],sell=0;

        for(int i=1;i<prices.size();i++){
            // checking minimum buy
            buy = min(buy,prices[i]);
            // getting minimum profit
            sell= prices[i]-buy;
            // updating the max profit
            max_profit = max(max_profit,sell);
        }
        return max_profit;
    }
};