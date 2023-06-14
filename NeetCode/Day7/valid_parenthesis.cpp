// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack <char> stk;

        for(int i=0;i<s.size();i++)
        {   
            if(stk.empty() || s[i] == '(' || s[i]=='[' || s[i]=='{')
            {
                stk.push(s[i]);
            }

            else if(s[i]==')' && stk.top()=='(')
            {
                stk.pop();
            }

            else if(s[i]==']' && stk.top()=='[') stk.pop();

            else if(s[i]=='}' && stk.top() =='{') stk.pop();

            else{
                stk.push(s[i]);
            }
        }

        if(stk.empty())return true;
        return false;
    }
};