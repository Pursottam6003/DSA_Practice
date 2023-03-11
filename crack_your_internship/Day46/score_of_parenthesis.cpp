// https://leetcode.com/problems/score-of-parentheses/description/
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack <int> stk;

        int ct=0;
        for(auto c:S)
        {
            if(c=='(')
            {   stk.push(ct);
                ct=0;
            }
            else 
            {
                ct += stk.top() +  max(1,ct);
                stk.pop();
            }
        }
        return ct;
    }
};