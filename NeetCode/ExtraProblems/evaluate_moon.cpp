#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main()
{
    lli t;
    cin>>t;

    int res=0;
    while(t--)
    {
        lli n,m,h;
        cin>>n>>m>>h;
        
        vector <lli> eng_cp(n),power(n);

        for(int i=0;i<n;i++)
        {
            cin>>eng_cp[i];
        }

        for(int i=0;i<m;i++)
        {
            cin>>power[i];
        }

//      
        lli maxi=0;
        for(int i=0;i<m;i++)
        {
            maxi = power[i]* h;
            res +=  min(maxi,eng_cp[i]);
        }
    
    }
    cout<<res<<endl;
}