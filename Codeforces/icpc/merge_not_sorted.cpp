#include <iostream>
#include <vector>

using namespace std;

vector<int> constructArrays(int n, const vector<int>& c) {
    vector<int> A, B;
    for (int i = 0; i < 2 * n; ++i) {
        if (i % 2 == 0) {
            A.push_back(c[i]);
        } else {
            B.push_back(c[i]);
        }
    }
    return A;
}

vector<int> merge(const vector<int>& A, const vector<int>& B) {
    vector<int> C;
    int i = 0, j = 0;

    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            C.push_back(A[i]);
            ++i;
        } else {
            C.push_back(B[j]);
            ++j;
        }
    }

    while (i < A.size()) {
        C.push_back(A[i]);
        ++i;
    }

    while (j < B.size()) {
        C.push_back(B[j]);
        ++j;
    }

    return C;
}

int main() {
    int n;
    cin >> n;

    vector<int> c(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> c[i];
    }

    vector<int> A = constructArrays(n, c);
    vector<int> B = merge(A, c);

    if (B == c) {
        for (int i = 0; i < n; ++i) {
            cout << A[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < n; ++i) {
            cout << B[i] << " ";
        }
    } else {
        cout << -1;
    }

    return 0;
}
