#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main()
{
    lli n;
    cin>>n;

    vector <lli> vec(n,0);
    lli ar_sum=0;
    for(int i=0;i<n-1;i++)
    {
        cin>>vec[i];
        ar_sum += vec[i];
    }

    lli sum = (n*(n+1))/2;

    cout<<sum - ar_sum<<endl;

    return 0;

}