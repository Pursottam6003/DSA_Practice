#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
int main()
{
    lli n;
    cin>>n;

    vector <lli> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }

    sort(vec.begin(),vec.end());

    for(int i=0;i<n;i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}