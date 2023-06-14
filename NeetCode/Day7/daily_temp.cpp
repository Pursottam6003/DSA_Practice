// https://leetcode.com/problems/daily-temperatures/description/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector <int> res(n,0);

        stack <int> stk;

        // stk.push(n-1);
        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() && temp[stk.top()] <= temp[i])
            {
                // pop until it becomes equal 
                stk.pop();
            }

            if(stk.empty())
            {
                res[i] = 0;
            }
            else if(temp[stk.top()] > temp[i])
            {
                res[i] = stk.top() -i;
            }

            // for the first time it will push theat element 
            stk.push(i);
        }
        return res;

    }
};
/*
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
*/