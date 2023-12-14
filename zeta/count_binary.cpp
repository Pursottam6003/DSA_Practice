#include <iostream>
#include <vector>
#include <string>

int countPatterns(const std::string& binaryString) {
    int n = binaryString.length();
    std::vector<int> onesPrefixSum(n + 1, 0);
    std::vector<int> zerosPrefixSum(n + 1, 0);

    int totalCount = 0;

    // Calculate prefix sums for 1's and 0's
    for (int i = 0; i < n; ++i) {
        onesPrefixSum[i + 1] = onesPrefixSum[i] + (binaryString[i] == '1' ? 1 : 0);
        zerosPrefixSum[i + 1] = zerosPrefixSum[i] + (binaryString[i] == '0' ? 1 : 0);
    }

    // Calculate occurrences using prefix sums
    for (int i = 2; i < n; ++i) {
        if (binaryString[i - 2] == '0' && binaryString[i - 1] == '1' && binaryString[i] == '0') {
            // Occurrence of "010"
            totalCount += onesPrefixSum[i] - onesPrefixSum[i - 1];
        } else if (binaryString[i - 2] == '1' && binaryString[i - 1] == '0' && binaryString[i] == '1') {
            // Occurrence of "101"
            totalCount += zerosPrefixSum[i] - zerosPrefixSum[i - 1];
        }
    }

    return totalCount;
}

int main() {
    // Example usage:
    std::string binaryString = "00101";
    int result = countPatterns(binaryString);
    std::cout << result << std::endl;

    return 0;
}
