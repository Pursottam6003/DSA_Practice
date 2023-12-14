// Given A String Consist Only 2 char 'a' and 'b'. Your Have To Find Lexicographically Smaller Subsequence Of Length K with Minimum Of X Number Of 'b' char. Ex. s='abab' k=3 X=2 ans='abb'
 #include <iostream>
#include <string>

std::string find_lexicographically_smaller_subsequence(const std::string& s, int k, int x) {
    std::string result;

    for (char ch : s) {
        if (ch == 'a') {
            // If 'a' is needed in the subsequence and it won't exceed the length K
            if (k - result.length() > x) {
                result.push_back('a');
            }
        } else {  // ch == 'b'
            // If 'b' is needed in the subsequence and it won't exceed the allowed count X
            if (x > 0) {
                result.push_back('b');
                x--;
            }
        }
    }

    return result;
}

int main() {
    std::string s = "abab";
    int k = 3;
    int x = 2;
    std::string ans = find_lexicographically_smaller_subsequence(s, k, x);
    std::cout << ans << std::endl;

    return 0;
}
