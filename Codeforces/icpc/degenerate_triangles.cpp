
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    int N;
    cin >> N;
 
    int ma = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
 
        ma = max(ma, a);
        sum += a;
    }
 
    if (ma > 2 * (sum - ma)) cout << sum - ma;
    else cout << sum / 3;
    return 0;
}