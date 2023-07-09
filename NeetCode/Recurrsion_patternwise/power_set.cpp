void recursion(int idx,string s,string str,vector <string> &res)
{
    if(idx == s.size())
    {
        res.push_back(str);
        return;
    }
    
    str.push_back(s[idx]);
    recursion(idx+1,s,str,res);
    str.pop_back();
    recursion(idx+1,s,str,res);
    
}

vector<string> generateSubsequences(string s)
{
    // Write your code here.
    string str;
    vector <string> res;
    recursion(0,s, str, res);
    return res;
}