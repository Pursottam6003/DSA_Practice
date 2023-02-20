// https://practice.geeksforgeeks.org/problems/equalize-an-array3405/1

typedef long long int lli;
#define mod 1000000007
class Solution{
public:
    int equalizeArray(int n, int k, int arr[]){
        // code here
        sort(arr,arr+n);
        
        int mid=0;
        if(n%2==1)
        {
            mid=n/2;
        }
        else mid=n/2 -1;
        
         for(long long int i=0;i<n;i++){
   
          if(  (abs(arr[i]-arr[mid]))%k!=0){
              return -1;
          }
      }
        lli steps=0,diff;
        for(lli i=0;i<n;i++)
        {   
            diff = abs(arr[i]-arr[mid]);
            steps += (diff/k) % mod;
        }
        return steps%mod;
       
    }
};