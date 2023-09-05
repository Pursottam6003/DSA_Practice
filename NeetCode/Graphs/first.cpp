#include <bits/stdc++.h>
using namespace std;

int getMaxCount(vector<int> &people, vector<char> &status)
{
    int n = people.size();
    int m = status.size();

    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int ele = people[i];

        if (status[i] == '+')
        {
            prefix[i + 1] = prefix[i] + people[i];
        }

        else if (status[i] == '-')
        {
            prefix[i + 1] = prefix[i] - people[i];
        }
    }
    int res = 0;
    for (int i = 0; i <= n; i++)
    {
        res = max(res, prefix[i]);
    }

    return res;
}
int main()
{
    vector<int> people = {1, 2, 1};

    vector<char> status = {'+', '-', '+'};

    cout << getMaxCount(people, status) << endl;
}