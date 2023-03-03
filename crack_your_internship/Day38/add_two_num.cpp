// https://leetcode.com/problems/sum-of-two-integers/submissions/908175771/
class Solution {
public:
    int getSum(unsigned a, unsigned b) {

    unsigned c; 
    while(b !=0 ) {
        c = (a&b);  // getting carry
        a = a ^ b; // sum without carry
        b = (c)<<1; // left shifting with that value in b 
    }
      return a;
    }
};