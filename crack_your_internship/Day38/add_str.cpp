//https://leetcode.com/problems/add-strings/description/
class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string res="";
        int n = num1.size()-1, m = num2.size()-1;

        int s=0;
        while(n>=0 || m>=0 || s>0)
        {   
            s += (n>=0) ? num1[n--]-'0' : 0; 
            s += (m>=0) ? num2[m--]-'0' : 0;

            res = to_string((s%10)) + res;
            s = s/10;
        }
        return res;
    }
};