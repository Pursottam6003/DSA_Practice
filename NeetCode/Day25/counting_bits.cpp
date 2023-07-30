// Brute force
// https://leetcode.com/problems/counting-bits/description/

class Solution
{
public:
    int ct_bits(int n)
    {
        int res = 0;
        while (n)
        {
            n = (n & (n - 1));
            res++;
        }
        return res;
    }
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            res[i] = ct_bits(i);
        }
        return res;
    }
};

/// @brief efficient approach
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1, 0);

        int ct = 0;
        for (int i = 0; i <= n; i++)
        {
            // if it is odd
            if (i & 1)
            {
                ct = res[i >> 1] + 1;
            }
            else
            {
                ct = res[i >> 1];
            }

            res[i] = ct;
        }
        return res;
    }
};

// https://www.codingninjas.com/studio/problems/count-total-set-bits_784?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

int countSetBits(int N)
{
    // Write your code here
    int d = 2, ans = 0, x = N;

    while (x)
    {
        // Using the Mathematical formula explained in the Approach.
        ans += ((N + 1) / d) * (d / 2) + max((N + 1) % d - d / 2, 0);
        // Window size double every time we shift to the next left bit.
        d *= 2;
        x /= 2;
    }

    return ans;
}