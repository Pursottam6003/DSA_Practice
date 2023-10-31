#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
int main()
{
    lli n,m,a;

    cin>>n>>m>>a;

    lli len = n/a;
    lli bred = m/a;

    if(n%a !=0) len++;
    if(m%a !=0) bred++;


    // lli ans = ceil(m/a) * ceil(n/a);
    cout<<(len*bred)<<endl;
}