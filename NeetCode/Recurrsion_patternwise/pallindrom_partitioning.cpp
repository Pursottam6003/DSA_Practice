class Solution {
public:

    bool isPallindrome(string &str,int start,int end)
    {   
        while (start <= end) {
        if (str[start++] != str[end--])
            return false;
        }
        return true;
    }
    void recurrsion(int ind,string str,vector <string> &ds,vector<vector<string>> &res)
    {
        if(ind ==str.size())
        {
            res.push_back(ds);
            return;
        }

        for(int i=ind;i<str.size();i++)
        {   
            string temp = str.substr(ind,i-ind+1);

            if(isPallindrome(str,ind,i))
            {
                ds.push_back(temp);
                recurrsion(i+1,str,ds,res);
                ds.pop_back();
            }
        }
        
    }

    vector<vector<string>> partition(string s) {
        vector <string> ds;
        vector <vector<string>> res;

        recurrsion(0,s,ds,res);
        return res;
    }
};