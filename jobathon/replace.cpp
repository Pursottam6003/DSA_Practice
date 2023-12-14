#include <iostream>
#include <unordered_map>

int maxLength(int n, std::string str) {
    int maxLength = 0;
    std::unordered_map<char, int> charIndex;

    // Use two pointers to create a sliding window
    int left = 0, right = 0;

    while (right < n) {
        // If the character is not in the current substring or its index is before the left pointer
        if (charIndex.find(str[right]) == charIndex.end() || charIndex[str[right]] < left) {
            // Update the character's index
            charIndex[str[right]] = right;
            // Move the right pointer to the next character
            right++;
        } else {
            // Move the left pointer to the right of the repeated character
            left = charIndex[str[right]] + 1;
        }

        // Update the maximum length
        maxLength = std::max(maxLength, right - left);
    }

    return maxLength;
}

// Example usage
int main() {
    int n = 4;
    std::string str = "zdde";
    int result = maxLength(n, str);
    std::cout << result << std::endl;

    return 0;
}
