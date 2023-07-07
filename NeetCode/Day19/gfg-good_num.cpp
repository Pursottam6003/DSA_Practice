//{ Driver Code Starts
// Initial Template for C++
// iterative soln
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
// iterative soln
class Solution {
  public:
  
    bool checkValid(int num,int d)
    {   
        int prev = num%10;
        num = num/10;
        
        if(prev ==d) return false;
        
        while(num>0)
        {
            int curr= num%10;
            
            if(curr <= prev || curr==d) return false;
            
            // if not ie good digit 
            prev = curr+prev;
            num = num/10;
        }
        
        return true;
    }
    vector<int> goodNumbers(int L, int R, int D) {
        // code here
        vector <int> res;
        
        for(int num=L;num<=R;num++)
        {
            if(checkValid(num,D))
            {
                res.push_back(num);
            }
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends

// recursive soln
class Solution {
  public:
    
    bool checkValid(int num,int d,int prev)
    {   
        if(num ==0) return true;
        
        int curr= num%10;
        if(curr <= prev || curr==d) return false;
        
        num = num/10;
        if(prev ==-1)
        {
            prev = curr;
        }
        else 
        {
            prev = curr+prev;
            
        }
        return checkValid(num,d,prev);
    }
    void findGoodNums(int L,int R,int D,vector <int> &res)
    {
        // base case 
        for(int i=L;i<=R;i++)
        {
            if(checkValid(i,D,-1))
            {
                res.push_back(i);
            }
        // findGoodNums(L,R,D,res);
        }
    }
    vector<int> goodNumbers(int L, int R, int D) {
        // code here
        vector <int> res;
        findGoodNums(L,R,D,res);
        
        return res;
    }
};