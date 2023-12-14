#include <iostream>
#include <string>

using namespace std;

string processUsername(string str) {
    int i = str.size() - 1;
    while (isdigit(str[i])) {
        --i;
    }
    return str.substr(0, i + 1);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;
        cout << processUsername(str) << endl;
    }

    return 0;
}