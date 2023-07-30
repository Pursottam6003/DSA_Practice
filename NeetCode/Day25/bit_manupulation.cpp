
// https://www.codingninjas.com/studio/problems/bit-manipulation_8142533?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
vector<int> bitManipulation(int num, int k)
{
    // Write your code here.
    vector<int> res(3, 0);

    int n = num;
    res[0] = ((n >> (k - 1)) & 1);
    res[1] = num | (1 << k - 1);
    res[2] = num & ~(1 << k - 1);
    return res;
}