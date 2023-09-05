#include <iostream>
#include <vector>

using namespace std;

int getMinWildcard(vector<string> &patterns)
{
    if (patterns.empty())
    {
        return 0;
    }

    int n = patterns.size();
    int m = patterns[0].size();
    int ans = 0;

    for (int i = 0; i < m; ++i)
    {
        char targetChar = patterns[0][i];

        for (int j = 1; j < n; ++j)
        {
            char currentChar = patterns[j][i];

            if (currentChar != '?' && currentChar != targetChar)
            {
                ans++;
                break; // No need to check this position further
            }
        }
    }

    return ans;
}

int main()
{
    vector<string> patterns = {"bug", "gub", "g?a"};
    int result = getMinWildcard(patterns);
    cout << result << endl; // Output: 2

    return 0;
}
