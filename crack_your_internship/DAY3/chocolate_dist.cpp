//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        long long int res=INT_MAX;
        // sort the array 
        sort(a.begin(),a.end());
        long long t=0;
        for(int i=0;i<n-m+1;i++)
        {   // iterate upto the element n-m+1 th 
            t=(a[i+m-1]-a[i]);
            // since we need to find upto the m th childresn so we consider this
            res = min(res,t);
        }
        return res;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Endsv