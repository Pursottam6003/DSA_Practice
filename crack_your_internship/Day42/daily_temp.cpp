class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        stack <int> stk;
        int s = temp.size();
        vector <int> res(s,0);

        int ct=0;
        for(int i =s-1;i>=0;i--)
        {
            while(!stk.empty() && temp[stk.top()] <= temp[i] )
            {
                stk.pop();
            }
            
            if(stk.empty())
            {
                res[i] = 0;
            }
            else 
            {
                res[i] = stk.top()-i;
            }
            stk.push(i);
        }
        return res;
    }
};