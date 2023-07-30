// https://www.codingninjas.com/studio/problems/check-whether-k-th-bit-is-set-or-not_5026446?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
bool isKthBitSet(int n, int k)
{
    // Write your code here.
    // check wheather kth bit is set or not
    if ((n >> (k - 1)) & 1)
        return true;
    return false;
}