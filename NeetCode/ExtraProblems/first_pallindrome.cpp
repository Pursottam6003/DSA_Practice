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
    string firstPalindrome(vector<string>& words) {
        
        for(int i=0;i<words.size();i++)
        {
            if(isPallindrome(words[i])) return words[i];
        }

        return "";
        
    }
};