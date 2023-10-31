#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


int getDigit(int num)
{
    int res=0;
    while(num)
    {
        int t = num %10;
        num = num/10;
        res = res + t;
    }
    return res;
}
int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        lli n,k;
        cin>>n>>k;
        int resNum = 0;
        for(int i=0;i<20;i++)
        {   
            int num = n + i;
            int val = getDigit(num);
            if(val % k == 0)
            {
                resNum= num;
                break;
            }
        }
        cout<<resNum<<endl;
    }
}