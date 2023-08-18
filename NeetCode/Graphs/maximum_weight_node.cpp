#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &arr)
{
    int ans = INT_MIN;
    int res = -1;
    vector<int> weight(arr.size(), 0);

    for (int i = 0; i < arr.size(); i++)
    {
        int source = i;
        int dest = arr[i];

        // check it should not be -1
        if (dest != -1)
        {
            weight[dest] += source;

            if (ans <= weight[dest])
            {
                // update with the maxium ans
                ans = max(ans, weight[dest]);
                res = dest;
            }
        }
    }

    if (ans != INT_MIN)
    {
        return res;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << solution(arr) << endl;
}