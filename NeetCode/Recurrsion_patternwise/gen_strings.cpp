// 
void solve(string str,vector <string> &res,int n,int idx)
{
    // base case 
    if(idx == n)
    {
        res.push_back(str);
        return;
    }

    // first add 0 to string 
    solve(str+'0',res,n,idx+1);

    // check since we need to check its consecutive elements are 1 

    // hence 
    if(str.back()!='1')
    {
        // if 1 is not present 
        solve(str+'1',res,n,idx+1);
    }
}

vector<string> generateString(int n) {
    // Write your code here.

    vector <string> res;
    string str;

    solve(str,res,n,0);
    return res;
}