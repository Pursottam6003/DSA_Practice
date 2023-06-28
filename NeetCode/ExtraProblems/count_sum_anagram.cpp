#include <iostream>
#include <unordered_map>
#include <string>

int calculateSumOfWords(const std::string& jumbledWords) {
    std::unordered_map<std::string, int> wordToInteger = {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };

    int sumOfIntegers = 0;

    // Iterate through the jumbled words
    size_t i = 0;
    while (i < jumbledWords.length()) {
        // Check if a word starting from the current position matches any word in the unordered map
        for (const auto& entry : wordToInteger) {
            const std::string& word = entry.first;
            if (jumbledWords.compare(i, word.length(), word) == 0) {
                // Add the corresponding integer value to the sum
                sumOfIntegers += entry.second;
                // Move the index forward by the length of the word
                i += word.length();
                break;
            }
        }

        // If no match is found, move to the next character
        ++i;
    }

    return sumOfIntegers;
}

int main() {
    std::string jumbledWords = "ehfrzeevteeonoir";
    int sumOfIntegers = calculateSumOfWords(jumbledWords);
    std::cout << sumOfIntegers << std::endl;

    return 0;
}
