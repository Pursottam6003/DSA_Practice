class Solution {
public:

    int evaluate(int a,int b,string oper)
    {   int ans;
        if(oper =="+")
            ans = ((a) + ( b));
        else if(oper =="-")
        {
            ans = a - b;
        }

        else if(oper == "*")
        {
            ans = a *b ;
        }

        else ans = a/b;
        return ans;
    }
    int evalRPN(vector<string>& str) {
        set <string> s = {"+","-","*","/"};

        stack <string> stk;
        int a=0,b=0;
        for(int i=0;i<str.size();i++)
        {
            if(s.count(str[i]))
            {
                b = stoi(stk.top());
                stk.pop();
                a = stoi(stk.top());
                stk.pop();
                a = evaluate(a,b,str[i]);
                stk.push(to_string(a));
            }

            else 
            {
                stk.push(str[i]);
            }
        }

      

        return stoi(stk.top());

    }
};