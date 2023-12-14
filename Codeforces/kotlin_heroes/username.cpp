#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

void solve_question(string str)
{
    int len = str.size()-1;

    int num_ct=0,char_ct=0;
    string res;
    for(int i=0;i<len;i++)
    {
        if(isalpha(str[i]))
        {
            res.push_back(str[i]);
            char_ct++;
        }

        
        else if( (i>0 && isdigit(str[i]) && isalpha(str[i-1])) || num_ct==0)
        {
            res.push_back(str[i]);
            num_ct++;
        }
        else if((i>0 && isdigit(str[i])  && isdigit(str[i-1]) && char_ct >=1) )
        {
            break;
        }
        else 
        {
            if(isalpha(str[i])) char_ct++;
            if(isdigit(str[i])) num_ct++;
            res.push_back(str[i]);
        }
        
    }

    num_ct=0,char_ct=0;
    string ans;
    int itr=0;

    while(itr<res.size())
    {
        if(isalpha(res[itr]))
        {
            ans.push_back(res[itr]);
            char_ct++;
        }
        else if(isdigit(res[itr]) && num_ct>=2)
        {
            ans.push_back(res[itr]);
            num_ct++;
        }

        else if(num_ct >=2 && char_ct >=1)
        {
            break;
        }
        itr++;
    }

    cout<<ans<<endl;
}

 
int main()
{
    lli t;
    cin>>t;

    while(t--)
    {
        string str;
        cin>> str;
        solve_question(str);
    }


}