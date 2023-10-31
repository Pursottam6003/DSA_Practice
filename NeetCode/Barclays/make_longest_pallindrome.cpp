#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i][i] = arr[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (arr[i] == arr[j]) {
                dp[i][j] = arr[i] + dp[i + 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    int maxPalindromeSum = dp[0][n - 1];
    vector<int> result;

    int i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] == arr[j]) {
            result.push_back(arr[i]);
            i++;
            j--;
        } else {
            if (dp[i][j - 1] > dp[i + 1][j]) {
                result.push_back(arr[j]);
                j--;
            } else {
                result.push_back(arr[i]);
                i++;
            }
        }
    }

    if (i == j) {
        result.push_back(arr[i]);
    }

    for (int k = result.size() - 1; k >= 0; k--) {
        cout << result[k] << " ";
    }

    return 0;
}
