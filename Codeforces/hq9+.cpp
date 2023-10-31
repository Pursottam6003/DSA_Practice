#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

bool hq9(string str)
{
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='H' || str[i]=='Q' || str[i]=='9' || str[i]=='+')
        {
            return true;
        }
    }
    return false;
}



int main()
{
    string str;
    cin>>str;

    hq9(str)==1 ? cout<<"YES"<<endl : cout<<"NO"<<endl;    
    return 0;
}