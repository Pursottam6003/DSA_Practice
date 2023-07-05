//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    int res=0;
    int sign=1;
    int implement_atoi(string str,int i,int n)
    {   
        if(i==n) return res*sign;
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (i>=1 && str[i]=='-' || str[i]=='+')) return -1;
        
        // if(n>1 && str[1]=='-' || str[i]=='+') return -1;
        int val = str[i]-'0';
        
        if(str[i]=='-') 
        {
            sign =-1;
            val =0;
        }
        res = res*10+val;
        
        
        return implement_atoi(str,i+1,n);
    }
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        
        return implement_atoi(str,0,str.size());
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends




// good implementation 
int atoi(string str) {
       int ans=0, start=0;
       if (str[0]=='-'){
           start=1;
       }
       for (int i=start; i<str.size(); i++){
           if (str[i]>='0' && str[i]<='9'){
               ans=ans*10+(str[i]-'0');
           }
           else{
               return -1;
           }
       }
       if (str[0]=='-'){
           return -ans;
       }
       return ans;
   }