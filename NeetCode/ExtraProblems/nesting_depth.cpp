class Solution {
public:
    int maxDepth(string s) {
        
        int res=INT_MIN;

        stack <char> stk;
        int left=0;
        int right=0;
        for(int i=0;i<s.size();i++)
        {   
            if( s[i]=='(' || s[i]=='[' || s[i]=='{')
            {   left++;
                stk.push(s[i]);
            }

            else if(s[i]==')' && stk.top()=='(') 
            {   right++;
                stk.pop();
            }

            else if(s[i]==']' && stk.top()=='[')
            {   right++;
                stk.pop();
            }
            else if(s[i] =='}' && stk.top()=='{')
            {   right++;
                stk.pop();
            }

            int t = left-right;
            res = max(res,t);
        }

        return res;
    }
};