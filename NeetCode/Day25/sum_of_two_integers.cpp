// https://leetcode.com/problems/sum-of-two-integers/description/
class Solution
{
public:
    int getSum(int a, int b)
    {
        // initialise carry with 0
        unsigned carry = 0;

        // run a loop until b becomes 0
        while (b != 0)
        {
            carry = a & b;    // and opeartion to find the carry
            a = a ^ b;        // to store the xor opearation result
            b = (carry << 1); // update the value with left shift of b
        }

        return a;
    }
};