// https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        
        int m = a.size() -1;
        int n = b.size() -1;
        
        string res;
        int ct=0;
        // unitil the size is not becomes 0 of each string
        while(m>=0 || n>=0 || ct==1)
        {   
            //int sum=ct; // initialsize the sum with prev counter
            ct += (m>=0) ? a[m--]-'0' :0;
            ct += (n>=0) ? b[n--]-'0' :0;


            // string in ouput
            res= to_string(ct&1)+res;
            // divinding the number
            ct = ct >>1; 
        }
        
        // reverse the string
        //reverse(res.begin(),res.end());
        return res;
    }
};