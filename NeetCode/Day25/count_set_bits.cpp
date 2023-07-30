// https://leetcode.com/problems/number-of-1-bits/description/
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {

        int ct = 0;
        while (n)
        {
            n = (n & (n - 1));
            ct++;
        }
        return ct;
    }
};