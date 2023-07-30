// https://www.codingninjas.com/studio/problems/set-the-rightmost-unset-bit_8160456?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
int setBits(int N)
{
    // Write your code here.
    // set the rightmost bit

    if ((N & (N + 1)) == 0)
        return N;

    return (N | (N + 1));
}

// https://practice.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1
class Solution
{
public:
    int setBit(int N)
    {
        // Write Your Code here
        if (N & (N + 1))
            return N | (N + 1);

        return N;
    }
};