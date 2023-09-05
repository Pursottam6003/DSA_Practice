#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{

    int res = 0;
    int n = height.size();
    vector<int> left(n, 0), right(n, 0);

    // initialize the parameters
    left[0] = height[0], right[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(height[i], left[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(height[i], right[i + 1]);
    }

    int trapped = 0;

    for (int i = 0; i < n; i++)
    {
        trapped = min(left[i], right[i]) - height[i];
        res += trapped;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> height(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    cout << trap(height) << endl;
    return 0;
}