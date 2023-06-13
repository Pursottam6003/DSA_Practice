// https://leetcode.com/problems/valid-palindrome/description/
class Solution {
public:
    bool isPalindrome(string s) {
        string str="";

        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                str += s[i];
            }

            else if(s[i] >='A' && s[i] <='Z') 
            {
                str += tolower(s[i]);
            }

            else if(s[i] >='0' && s[i] <='9')
            {
                str += s[i];
            }
        }
        int i=0,j=str.size()-1;

        while(i<j)
        {
            if(str[i] != str[j]) return false;

            i++,j--;
        }
        return true;
    }
};


class Solution {
public:
    bool isPalindrome(string str) {
        
        string s;
        for(int i=0;i<str.size();i++)
        {   
            
            if(str[i] >='A' && str[i]<='Z')
            {
                s.push_back((str[i]+32));
            }
            if(str[i] >='a' && str[i] <='z' || (str[i] >='0' && str[i] <='9')){
                s.push_back(str[i]);
            }
        }
        
        bool res=true;
        
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i] != s[s.size()-i-1])
            {
                res=false;
                break;
            }
        }
        return res;
    }
};