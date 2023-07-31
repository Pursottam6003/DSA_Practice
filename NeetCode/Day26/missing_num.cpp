// https://www.codingninjas.com/studio/problems/one-odd-occurring_4606074?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
int missingNumber(int n, vector<int> &arr)
{
    // Write your code here.
    int res = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        res = res ^ arr[i];
    }
    return res;
}