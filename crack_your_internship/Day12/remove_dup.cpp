// https://practice.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	   
	   string res;
	   unordered_set <char> myset;
	   for(int i=0;i<str.size();i++)
	   {
	       if(myset.count(str[i]))
	       {
	           continue;
	       }
	       else 
	       {
	           res.push_back(str[i]);
	       }
	       myset.insert(str[i]);
	   }
	   return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends