#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if (k << 1 < n || k == n)
        cout << "-1\n", exit(0);

    for (int i = 0; i < k - n/2 +1 /2; i++)
        cout << "()";

    for (int i = 0; i < n - k; i++)
        cout << '(';

    for (int i = 0; i < n - k; i++)
        cout << ')';

    for (int i = 0; i < k - (n/2 +1)/2; i++)
        cout << "()";
    cout << endl;
    return 0;
}