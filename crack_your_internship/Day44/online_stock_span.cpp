// https://leetcode.com/problems/online-stock-span/submissions/911945023/
class StockSpanner {
public:
    //    stack<pair<int, int>> s;
    // int next(int price) {
    //     int res = 1;
    //     while (!s.empty() && s.top().first <= price) {
    //         res += s.top().second;
    //         s.pop();
    //     }
    //     s.push({price, res});
    //     return res;
    // }

    stack <pair<int,int>> stk;

    int next(int price)
    {    int res=1;
        while(!stk.empty() && stk.top().first <= price)
        {    
            res += stk.top().second;
            stk.pop();
        }
        stk.push({price,res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */