
// https://leetcode.com/problems/remove-palindromic-subsequences/description/
class Solution {
public:

    bool isPallindrome(string str)
    {   
        int n=str.size();
        for(int i=0;i<str.size()/2;i++)
        {
            if(str[i] != str[n-i-1]) return false;
        }
        return true;
    }    
    
    int removePalindromeSub(string s) {
        
        // check the whole string first 

        if(s.size()==0)  return 0;
        if(isPallindrome(s)) return 1;

        return 2;
        // if it will be as pallindrome we can remove whole subtring in
        // single operation
    }
};