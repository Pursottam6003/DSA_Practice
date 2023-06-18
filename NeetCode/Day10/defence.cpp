#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int killAllMonsters(const vector<int>& A, const vector<int>& H, const vector<int>& B, int K) {
    // Create a vector of pairs to store monsters' x-coordinate and health
    vector<pair<int, int>> monsters;
    for (int i = 0; i < A.size(); i++) {
        monsters.push_back(make_pair(A[i], H[i]));
    }

    // Sort the monsters based on x-coordinate
    sort(monsters.begin(), monsters.end());

    // Iterate through sentinel positions
    for (int sentinelPos : B) {
        // Find the nearest monster on the left side using binary search
        auto leftIt = upper_bound(monsters.begin(), monsters.end(), make_pair(sentinelPos, INT_MAX));
        int leftIndex = leftIt - monsters.begin() - 1;
        int leftDistance = (leftIndex >= 0) ? (sentinelPos - monsters[leftIndex].first) : INT_MAX;
        int leftHealth = (leftIndex >= 0) ? monsters[leftIndex].second : 0;

        // Find the nearest monster on the right side using binary search
        auto rightIt = lower_bound(monsters.begin(), monsters.end(), make_pair(sentinelPos, -1));
        int rightIndex = rightIt - monsters.begin();
        int rightDistance = (rightIndex < monsters.size()) ? (monsters[rightIndex].first - sentinelPos) : INT_MAX;
        int rightHealth = (rightIndex < monsters.size()) ? monsters[rightIndex].second : 0;

        // Calculate the number of shots required
        int totalHealth = leftHealth + rightHealth;
        int shotsRequired = (totalHealth / K) + ((totalHealth % K > 0) ? 1 : 0);

        // Check if the number of shots required is <= number of sentinels available
        if (shotsRequired <= B.size()) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(M);
    vector<int> H(M);
    vector<int> B(N);

    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> H[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int result = killAllMonsters(A, H, B, K);
    cout << result << endl;

    return 0;
}