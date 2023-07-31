// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
class Solution
{
public:
    int minBitFlips(int a, int b)
    {

        int c = a ^ b;
        int res = 0;

        while (c)
        {
            if (c & 1)
                res++;
            c = c >> 1;
        }
        return res;
    }
};