// https://practice.geeksforgeeks.org/problems/subarrays-with-sum-k/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int nums[], int N, int k)
    {
        // code here
        
        int total_sub=0;
        // create a map to store the elements 

        unordered_map <int,int> mpp;

        int sum=0;
        for(int i=0;i<N;i++)
        {   
            sum +=nums[i];

            if(sum ==k)
            {
                // increment the total seq 
                total_sub++;
            }

            // find the element into map 
            if(mpp.find(sum-k) != mpp.end())
            {
                total_sub = mpp[sum-k]+total_sub;
            }
            // if sum exitsts 
            if(mpp.find(sum) != mpp.end()) mpp[sum]++;
            // otherwise addd them 
            else 
            {
                mpp[sum]=1;
            }
        }

        return total_sub;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends