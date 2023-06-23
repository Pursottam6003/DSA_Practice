class Solution {
public:
    string makeSmallestPalindrome(string s) {
        string res;
        int n = s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i] >= s[n-1-i])
            {
                res.push_back((s[n-i-1]));
            }
            else 
            {
                res.push_back(s[i]);
            }
        }

        string s2 = res;

        reverse(s2.begin(),s2.end());

        if(n%2==0)
        {
            return res+s2;
        }

        return res+s[n/2]+s2;
    }
};

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        
        int low=0,high = s.size()-1;

        while(low < s.size())
        {
            s[low] = min(s[high],s[low]);
            low++;
            high--;
        }

        return s;
    }
};
// better approahc 
class Solution {
public:
    string makeSmallestPalindrome(string s) {

        int n = s.size();
        for(int i=0;i<n;i++)
        {
            s[i] = s[n-i-1] = min(s[i],s[n-i-1]);
        }   
        return s;
    }
};