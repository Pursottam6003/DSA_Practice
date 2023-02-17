// https://leetcode.com/problems/power-of-four/submissions/899617016/
// class Solution {
// public:
//        bool isPowerOfFour(int num) {
//         while(num > 1) {
//             if(num % 4)return false;
//             num /= 4;
//         }
//         return num == 1;
//     }
// };

class Solution {
    
    public:
        bool isPowerOfFour(int num){
            
            if(num ==0) return false;
            double check = log10(num)/log10(4);
            
            if(ceil(check) == floor(check)) return true;
            
            return false;
        }
};