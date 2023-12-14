#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

long long find_max_product(int n, std::vector<int>& a, std::vector<int>& b) {
    // Sort both arrays in descending order
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(b.begin(), b.end(), std::greater<int>());

    long long result = 1;

    for (int i = 0; i < n; ++i) {
        if (a[i] + b[i] > a[i] * b[i]) {
            // Add the corresponding element from B
            result = (result * (a[i] + b[i])) % MOD;
        } else {
            // Multiply the elements
            result = (result * (a[i] * b[i])) % MOD;
        }
    }

    return result;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        std::vector<int> b(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }

        long long result = find_max_product(n, a, b);
        std::cout << result << std::endl;
    }

    return 0;
}
