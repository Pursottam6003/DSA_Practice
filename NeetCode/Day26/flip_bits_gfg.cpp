// https://practice.geeksforgeeks.org/problems/flip-bits0240/1
class Solution
{
public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int ones = 0, zeros = 0, maxZeros = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
                ones++;
            if (zeros < 0)
                zeros = 0;

            if (a[i] == 0)
                zeros++;
            else
                zeros--;

            maxZeros = max(zeros, maxZeros);
        }
        return ones + maxZeros;
    }
};
