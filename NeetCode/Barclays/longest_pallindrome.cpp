// longest pallindrome substring 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int expandFromMiddle(string s, int left, int right){
        if(s.length() == 0 || left > right) return 0;
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        
        int n = s.length();
        if(n == 0) return "";
        int start = 0, end = 0;
        for(int i = 0; i < n; i++){
            int len1 = expandFromMiddle(s, i, i);
            int len2 = expandFromMiddle(s, i, i+1);
            int len = max(len1, len2);
            if(len > end - start){
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start, end-start+1);    
    }

};


int main()
{
    Solution sol;
    string s = "babad";
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}