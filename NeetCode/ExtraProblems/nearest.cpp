#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int accountBalanceAfterPurchase(int x)
    {

        int i;
        for (i = 0; i <= 100; i = i + 10)
        {
            if (i >= x)
                break;
        }

        int rem = x % 10;

        if (i != x && rem <= 4)
            i = i - 10;

        return 100 - i;
    }
};

int main()
{
    class Solution sol;
    int n;
    cin >> n;
    cout << sol.accountBalanceAfterPurchase(n) << endl;
}