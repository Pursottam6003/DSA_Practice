#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    int maxProfit(vector <int> &stocks)
    {
        int max_profit =0;
        for(int i=0;i<stocks.size();i++)
        {
            if(stocks[i] > stocks[i-1])
            {
                max_profit += stocks[i] - stocks[i-1];
            }
        }
        return max_profit;
    }
};
int main()
{

}