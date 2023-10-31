#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main()
{
    lli n,k;
    cin>>n>>k;

    // a5 = a+ (k-1)*d;
    lli num=0;
    if(k <= n/2)
    {
        num = 1+ (k-1)*2;
    }

    else 
    {   
        if(n&1) k--;

        num = 2+ (k-1- (n/2))*2;

        if(num==0) 
        {
            num = n;
        }
    }
    cout<<num<<endl;
    return 0;
}