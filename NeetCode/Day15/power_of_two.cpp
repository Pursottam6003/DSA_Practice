// https://leetcode.com/problems/power-of-two/submissions/983739791/
class Solution {
public:
    bool isPowerOfTwo(int n) {
       

       if(n <=0) return false;

       else  if(n & n-1)
       {
           return false;
       }
       return true;
    }
};

