// https://leetcode.com/problems/power-of-three/description/
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
        
//         if(n==0) return false;
        
//         if(n==1) return true;
            
//         if(n%3==0)
//             return isPowerOfThree(n/3);
//         return false;
//     }
// };

class Solution {
public:
    bool isPowerOfThree(int n)
    {
      if(n==0)return false;

      double a=log10(n)/log10(3);

      if(ceil(a)==floor(a))
          return true;

      return false;
    }
};