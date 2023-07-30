class Solution
{
public:
    int setKthBit(int N, int k)
    {
        // Write Your Code here

        int mask = 1 << k;
        N = N | mask;
        return N;
    }
};