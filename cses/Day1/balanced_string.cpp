// a string is called balanced if it has equal summed number of 'a's and 'c' is even  

// the summed no of b's and d's is even

// eg cdba is balanced

// aaccb is not balanced
// cdcdaabb is balanced

#include <iostream>
#include <string>

bool isBalanced(const std::string& str) {
    int countA = 0, countB = 0, countC = 0, countD = 0;

    for (char ch : str) {
        switch (ch) {
            case 'a': countA++; break;
            case 'b': countB++; break;
            case 'c': countC++; break;
            case 'd': countD++; break;
        }
    }

    bool condition1 = (countA + countC) % 2 == 0;
    bool condition2 = (countB + countD) % 2 == 0;

    return condition1 && condition2;
}

int main() {
    std::string inputStr;
    std::cin >> inputStr;

    if (isBalanced(inputStr)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}