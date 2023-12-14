#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
int main()
{
    lli n,m;
    cin>>n>>m;

    vector <lli> vec(m);

    for(int i=0;i<m;i++)
    {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    lli res=INT_MAX;
    

    for(int k=0;k<=m-n;k++)
    {
        res = min(res,(vec[k+n-1]-vec[k]));
    }
   
   
    cout<<res<<endl;  
    return 0;
}