#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    // Check if it's possible to construct a parentheses sequence
    if (K > N / 2) {
        cout << -1 << endl;
        return 0;
    }

    string sequence;
    sequence += '(';

    // Add alternating parentheses to ensure balance
    for (int i = 1; i < N - K; ++i) {
        sequence += (i % 2 == 1) ? '(' : ')';
    }

    // Add extra ')' characters in the middle
    sequence += ')';
    for (int i = 0; i < K; ++i) {
        sequence += ')';
        sequence += '(';
    }

    cout << sequence << endl;

    return 0;
}
