#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
int main()
{
    lli n,m;
    cin>>n>>m;

    vector <lli> vec(n);

    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());


    int res=INT_MAX;

    for(int i=0;i<(m-n+1);i++)
    {   int diff = vec[i+n-1]-vec[i];
        res = min(res,diff);
    }

    cout<<res<<endl;
  
    return 0;
}