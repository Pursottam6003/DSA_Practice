// https://www.codingninjas.com/studio/problems/two-numbers-with-odd-occurrences_8160466?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
vector<int> twoOddNum(vector<int> arr)
{
    // Write your code here.

    int xorr = 0;

    // find the commulative sor

    for (int i = 0; i < arr.size(); i++)
    {
        xorr ^= arr[i];
    }

    int cnt = 0;

    while (xorr)
    {
        if (xorr & 1)
            break;
        cnt++;
        xorr = xorr >> 1; // right shift karlo
    }

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] & (1 << cnt))
        {
            xor1 ^= arr[i];
        }

        else
        {
            xor2 ^= arr[i];
        }
    }

    if (xor2 > xor1)
        swap(xor1, xor2);

    return {xor1, xor2};
}