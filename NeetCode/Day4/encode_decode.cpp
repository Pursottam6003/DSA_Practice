//{ Driver Code Starts
// Initial Template for C++

// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

 
/*
 stack = []; curNum = 0; curString = ''
        for c in s:
            if c == '[':
                stack.append(curString)
                stack.append(curNum)
                curString = ''
                curNum = 0
            elif c == ']':
                num = stack.pop()
                prevString = stack.pop()
                curString = prevString + num*curString
            elif c.isdigit():
                curNum = curNum*10 + int(c)
            else:
                curString += c
        return curString 
*/   

class Solution{
public:
   string decodedString(string s){
       // code here
       int currNo=0;
       string currString="";
       int prevNo;
       string prevString;
       stack<string>stringstack;
       stack<int>numstack;
       for(int i=0;i<s.size();i++)
       {
           if(isdigit(s[i])) currNo = currNo*10 + (s[i]-'0');
           if(isalpha(s[i])) currString += s[i];
           if(s[i] == '[')
           {
               stringstack.push(currString);
               numstack.push(currNo);
               currNo=0;
               currString="";
           }
           if(s[i] == ']')
           {
               prevNo = numstack.top();
               numstack.pop();
               prevString = stringstack.top();
               stringstack.pop();
               
               while(prevNo--)
               {
                  prevString += currString;
               }
               currString = prevString;
           }
       }
       return currString;
       
       
   }
};
 

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends