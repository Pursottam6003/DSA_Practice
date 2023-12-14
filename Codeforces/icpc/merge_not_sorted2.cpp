#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


int findNext(vector<lli> &arr, int i, int n)
{
    int j = i+1;
    while(j<n)
    {
        if(arr[j]>arr[i])
            break;
        j++;
    }
    return j;
}

int main()
{
    lli n;
    cin>>n;

    vector<lli> arr(n);

    for(lli i=0;i<n;i++)
        cin>>arr[i];
    
    vector <lli> arr1,arr2;

    int ct1=0,ct2=0;
    for(int i=0;i<n;i++)
    {
        int j = findNext(arr,i,n);
        arr1.push_back(arr[i]);
        arr2.push_back(arr[j]);
    }

    cout<<"Array 1: ";
    for(int i=0;i<n/2;i++)
        cout<<arr1[i]<<" ";
    cout<<endl;
    cout<<"Array 2: ";
    for(int i=0;i<n/2;i++)
        cout<<arr2[i]<<" ";
    
    return 0;

}