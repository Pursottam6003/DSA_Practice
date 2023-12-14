#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> pos;
    int balance = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '+') {
            balance++;
        } 
        else if(s[i]=='-')
        {
            balance--;
        }

        if(balance <0 )
        {
            pos.push_back(i+1);
        }
        if(balance==0){
            pos.push_back(i + 1);
        }
    }
    if ((s.size()==1 && s[0]=='+') || balance==0 && pos.size()==1) {
        cout << "1 1\n";
    } 
    else if (balance == 0) {
        cout << pos[0] << " " << pos[pos.size()-1] << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}