#include <bits/stdc++.h>
using namespace std;


int binary_search(vector <int> &arr,int l,int r,int key)
{
    int mid = (l+r)/2;

    if(l>r)
    {
        return -1;
    }

    if(arr[mid]==key)
    {
        return mid;
    }
    else if(arr[mid] >key)
    {
        // serach left 
        return binary_search(arr,l,mid-1,key);
    }
    else 
    {
        return binary_search(arr,mid,r,key);
    }
    return -1;
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

    sort(arr.begin(),arr.end());
    // apply binary search 
    int key;
    cout<<"Enter the key to be searched"<<endl;
    cin>>key;
    int idx = binary_search(arr,0,n,key);
    // print the array 
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<"Yes the element is present"<<idx +1<<endl;

}