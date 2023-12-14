#include <iostream>
#include <bits/stdc++.h>

#include <vector>

using namespace std;
const int MOD = 100000007;

std::vector<std::vector<int>> memo;

int countWaysToCutRod(int n, int r)
{
    if (r == 1 or n == 0)
    {
        return 1;
    }

    if (memo[n][r] != -1)
    {
        return memo[n][r];
    }

    memo[n][r] = (countWaysToCutRod(n-1, r) + countWaysToCutRod(n, r - 1)) % MOD;
    return memo[n][r];
}


int main()
{
    int n,r;
    cin >>n;
    cin >> r;
           

    memo.resize(n + 1, std::vector<int>(r + 1, -1));

    int ways = countWaysToCutRod(n, r);

    cout << "Number of ways to cut the rod into " << ways <<endl;

    return 0;
}