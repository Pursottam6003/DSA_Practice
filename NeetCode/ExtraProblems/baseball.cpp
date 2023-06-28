
/// https://leetcode.com/problems/baseball-game/description/
class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack <int> stk;
        for(string str: operations)
        {                
            int tp2;
            int tp1;
            if(str=="C" && !stk.empty())
            {
                stk.pop();
            }
            else if(str=="D" && !stk.empty())
            {   
                tp2 = stk.top();
                stk.push(tp2*2);
            }

            else if (str =="+" && !stk.empty())
            {   tp2 = stk.top();
                stk.pop();  
                tp1= stk.top();

                stk.push(tp2);

                int val = tp1+tp2;
                stk.push(val);
            }

            else 
            {
                stk.push(stoi(str));
            }
            
        }
        int res=0;
        while(stk.size() !=0)
        {
            res += stk.top();
            stk.pop();
        }   
        return res;
    }
};