#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

void solve_question(string str) {
    int len = str.size() - 1;

    int numCt = 0, charCt = 0;
    string res;

    for (int i = 0; i <= len; i++) {
        if (isalpha(str[i])) {
            res.push_back(str[i]);
            charCt++;
        } else if (i > 0 && isdigit(str[i]) && isalpha(str[i - 1])) {
            res.push_back(str[i]);
            numCt++;
        } else {
            break;
        }
    }
    cout << res << endl;
}

int main() {
    lli t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;
        solve_question(str);
    }

    return 0;
}
