
// https://www.youtube.com/watch?v=aguruSTZJRQ&t=227s
static unordered_set<string> s ({"+","-","*","/"});
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int res;
        for(int i=0;i<tokens.size();i++)
        {   
           // int curr = stoi(tokens[i]);
            if(s.find(tokens[i]) != s.end())
            {
                // if found operator 
                int b= stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                if(tokens[i]=="+") res = a+b;
                else if(tokens[i]=="-") res = a-b;
                else if(tokens[i]=="*") res = a*b;
                else res = a/b;

                stk.push(res);
            }

            else 
            {
                stk.push(stoi(tokens[i]));
            }
        }

        return stk.top();
    }
};