

 

 
void recursion(int open,int close,int n,string str,vector <string> &res)
{
    if(str.size() == 2*n)
    {
        // push the string into the vector 
        res.push_back(str);
        return;
    }
    // for open 
    if(open <n)
    {
        str.push_back('(');
        recursion(open+1,close,n,str,res);
        str.pop_back();
    }

    if (close < open) {
      str.push_back(')');
      recursion(open, close + 1, n, str, res);
      str.pop_back();
    }
}
vector<string> validParenthesis(int n){
    // Write your code here.
    string str;
    vector <string> res;

    recursion(0,0,n,str,res);
    return res;
}