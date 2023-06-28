// https://leetcode.com/problems/remove-outermost-parentheses/description/
class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string res;
        int open =0;
        for(auto c: s)
        {
            if(c =='(' &&  open++ >0 ) res.push_back(c);
            if(c==')' &&  open-- >1) res.push_back(c);
        }
        return res;
    }
};
// stack solution 

class Solution {
public:
    string removeOuterParentheses(string s) {

        string res;
        stack <char> stk;

        for(char i: s)
        {
            if(i=='(')
            {   
                if(stk.size() >0 )
                {
                    res += i;
                }
                stk.push(i);
            }

            else if(i==')') {
                if(stk.size() >1)
                {
                    res +=i;
                }
                stk.pop();
            }
        }   
        return res;
    }
};