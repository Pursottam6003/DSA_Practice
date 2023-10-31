#include <bits/stdc++.h>
using namespace std;
 
typedef long long int lli;
 
int main()
{
    string str;
    cin>>str;

    int len=0;

    // algo 

    // we need to find the subarray of size 7 or more 

    int templen=1;
    for(int i=1;i<str.size();i++)
    {   
        if(str[i] == str[i-1])
        {
            templen++;
        }

        else  
        {
            len = max(len,templen);
            templen = 1;
        }
    }
    len = max(len,templen);

    if(len <7) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
 
}