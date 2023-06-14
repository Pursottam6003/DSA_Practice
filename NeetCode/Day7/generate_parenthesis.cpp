class Solution {
public:

    void backTrack(int n , int open,int close,
string& str, vector <string> &res)
    {
        // if the size of string becomes equal 
        if(2*n == str.size())
        {
            // string is generated 
            res.push_back(str);
            return;
        }

        if(open < n)
        {   
            str.push_back('(');
            backTrack(n,open+1,close,str,res);
            str.pop_back(); //remove that element
        }

        if(close < open)
        {
            str.push_back(')');
            backTrack(n,open,close+1,str,res);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector <string> res;
        string str="";
        backTrack(n,0,0,str,res);
        return res;
    }
};