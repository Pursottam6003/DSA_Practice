// https://www.codingninjas.com/studio/problems/power-of-two_893061?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
bool isPowerOfTwo(int n)
{
    // Write your code here.
    if (n & (n - 1))
        return false;
    return true;
}
// https://leetcode.com/problems/power-of-two/submissions/
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {

        if (n <= 0)
            return false;

        if (n & (n - 1))
            return false;
        return true;
    }
};