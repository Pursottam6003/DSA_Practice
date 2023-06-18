class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
        int profit = INT_MIN;
        int buy = INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            buy = min(buy,prices[i]);

            int currProfit = prices[i] - buy;

            profit = max(profit,currProfit);
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
        int profit = 0;
        int buy = prices[0];
        for(int i=1;i<prices.size();i++)
        {

            if(buy > prices[i]) 
            {   
                // update buy 
                buy = prices[i];
            }
            
            int currProfit = prices[i] - buy;

            profit = max(profit,currProfit);
        }
        return profit;
    }
};