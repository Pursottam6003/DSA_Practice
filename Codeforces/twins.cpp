#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
int main()
{
    lli n;
    cin>>n;

    lli arr[n];


    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n,greater<int>());

    lli sum=0,coins=0;

    for(int i=0;i<n;i++) sum += arr[i];

    lli running_sum = 0;

    lli itr=0;
    while(running_sum <= sum)
    {
        running_sum += arr[itr];
        sum = sum - arr[itr];
        itr++;
        coins++;
    }
    cout<<coins<<endl;
}