// https://leetcode.com/problems/valid-parentheses/submissions/
class Solution {
public:
    bool isValid(string s) {
        
        stack <char> stk;
        // first insert the first char
        //stk.push(s[0]);

        for(int i=0;i<s.size();i++)
        {   
            if(stk.empty()) stk.push(s[i]);
            else if(s[i]=='(' || s[i]=='{' || s[i]=='[') 
            {
                stk.push(s[i]);
            }
            else if((s[i]=='}' && stk.top() =='{') || (s[i]==')' && stk.top()=='(') || (s[i]==']' && stk.top()=='['))
            {
                stk.pop();
            }
            else 
            {   
                stk.push(s[i]);
            }
        }

        if(stk.empty()) return true;
        return false;
    }
};