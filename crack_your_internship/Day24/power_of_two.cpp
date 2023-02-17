// https://leetcode.com/problems/power-of-two/description/
/* 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n<=0) return false;
          
        int p = log2(abs(n));
        if(abs(n) != pow(2,p) ) return false;
        else return true;
    }
};
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
         // if the number in negative we sh
         if(n <= 0) return false;
        
         else
         {
             if(n & n-1)
             {
                return false;
             }
         }
         return true;
    }
};
