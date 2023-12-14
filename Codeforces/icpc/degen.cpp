#include <iostream>
#include <vector>

using namespace std;

int count_triangles(int N, const vector<int>& A) {
    int total_triangles = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                total_triangles += (A[i] - 1) * (A[j] - 1) * (A[k] - 1);
            }
        }
    }

    return total_triangles;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int result = count_triangles(N, A);
    cout << result << endl;

    return 0;
}
