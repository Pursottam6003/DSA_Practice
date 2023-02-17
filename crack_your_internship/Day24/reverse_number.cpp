// https://leetcode.com/problems/palindrome-number/description/
class Solution {
public:
bool isPalindrome(int x) {
    long long int i=x, n=0;
    while(i>0)
    {
        n=i%10+n*10;
        i/=10;
    }
    return n==x;
}
};