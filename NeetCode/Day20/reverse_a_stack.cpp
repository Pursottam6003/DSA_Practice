//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

   void insert_stk(stack <int> &stk,int temp)
    {
        if(stk.empty())
        {
            stk.push(temp);
            return;
        }
        
        int val = stk.top();
        stk.pop();
        insert_stk(stk,temp);
        stk.push(val);
    }
        void Reverse(stack<int> &stk){
        
        if(stk.empty()) return;
        int t = stk.top();
        stk.pop();
        Reverse(stk);
        insert_stk(stk,t);

        return;
        
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends