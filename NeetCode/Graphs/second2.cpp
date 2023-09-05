#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <set>

using namespace std;

int getMinWildcard(vector<string> &patterns)
{
    if (patterns.empty())
    {
        return 0;
    }

    int n = patterns.size();
    int m = patterns[0].size();

    string commonPattern = "";

    for (int j = 0; j < m; ++j)
    {
        set<char> distinctChars;
        for (int i = 0; i < n; ++i)
        {
            char c = patterns[i][j];
            if (c != '?')
            {
                distinctChars.insert(c);
            }
        }

        if (distinctChars.size() == 1)
        {
            commonPattern += *distinctChars.begin();
        }
        else
        {
            commonPattern += '?';
        }
    }

    return count(commonPattern.begin(), commonPattern.end(), '?');
}

int main()
{
    vector<string> patterns = {"bug", "gub", "gza"};
    int result = getMinWildcard(patterns);
    cout << result << endl; // Output: 2

    return 0;
}
