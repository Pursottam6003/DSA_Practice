#include <bits/stdc++.h>
using namespace std;

int sum_function(vector <int> &arr,int sum,int idx)
{
    if(idx == arr.size())
    {
        return sum;
    }
    sum += arr[idx];
    return  sum_function(arr,sum,idx+1);
}
int main()
{   
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }   
    
    int sum=0;
    sum = sum_function(arr,sum,0);
    cout<<sum<<endl;

}