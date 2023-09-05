#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{

    int n = gas.size();
    int total_surplus = 0; // it will give us a difference b/w gas & cost
    int surplus = 0;       // our tank
    int start = 0;         // and the index of gas station

    for (int i = 0; i < n; i++)
    {
        total_surplus += gas[i] - cost[i];
        surplus += gas[i] - cost[i];
        if (surplus < 0)
        {                  // if the tank goes -ve
            surplus = 0;   // reset our tank
            start = i + 1; // and update the stating gas station
        }
    }
    return (total_surplus < 0) ? -1 : start;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<string, string>> vec;

    for (int i = 0; i < n; i++)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;

        vec.push_back({s1, s2});
    }
}