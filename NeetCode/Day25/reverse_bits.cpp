// https://leetcode.com/problems/reverse-bits/solutions/54738/sharing-my-2ms-java-solution-with-explanation/
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res;

        if (n == 0)
            return 0;

        for (int i = 0; i < 32; i++)
        {
            // left shift first
            res = res << 1;
            if ((n & 1) == 1)
                res++;
            n = n >> 1; /// right shift to get the significant bits
        }
        return res;
    }
};