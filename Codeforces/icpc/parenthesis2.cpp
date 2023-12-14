#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(vector<string> &res, string curr, int open, int close, int max) {
    if (curr.size() == max * 2) {
        res.push_back(curr);
        return;
    }

    if (open < max) {
        curr.push_back('(');
        backtrack(res, curr, open + 1, close, max);
        curr.pop_back();
    }

    if (close < open) {
        curr.push_back(')');
        backtrack(res, curr, open, close + 1, max);
        curr.pop_back();
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    if (K > N || K % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<string> sequences;
    backtrack(sequences, "", 0, 0, N / 2);

    for (const string &sequence : sequences) {
        int lps = 0;
        for (int i = 0, j = sequence.size() - 1; i < j; ++i, --j) {
            if (sequence[i] == sequence[j]) {
                ++lps;
            }
        }

        if (lps == K / 2) {
            cout << sequence << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}