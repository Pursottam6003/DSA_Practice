// https://leetcode.com/problems/backspace-string-compare/description/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack <char> stk;
        for(int i=0;i<s.size();i++)
        {   
         
            
            if(s[i]=='#')
            {   if(!stk.empty())
                    stk.pop();
            }
            

            else 
            {
                stk.push(s[i]);
            }
        }

        string s1="",s2="";
        while(!stk.empty())
        {
            s1 += stk.top();
            stk.pop();
        }

        for(int i=0;i<t.size();i++)
        {       
            if(t[i]=='#')
            {
                if(!stk.empty())
                {
                    stk.pop();   
                }
            }

            else 
            {
                stk.push(t[i]);
            }
        }

        while(!stk.empty())
        {
            s2 += stk.top();
            stk.pop();
        }

        if(s1 != s2) return false;
        return true;

    }
};

/**
 // space optimised
 class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1, back;
        while (true) {
            back = 0;
            while (i >= 0 && (back > 0 || S[i] == '#')) {
                back += S[i] == '#' ? 1 : -1;
                i--;
            }
            back = 0;
            while (j >= 0 && (back > 0 || T[j] == '#')) {
                back += T[j] == '#' ? 1 : -1;
                j--;
            }
            if (i >= 0 && j >= 0 && S[i] == T[j]) {
                i--;
                j--;
            } else {
                break;
            }
        }
        return i == -1 && j == -1;
    }
};
*/