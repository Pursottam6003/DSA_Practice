#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_kill_all_monsters(int N, int M, vector<int>& A, vector<int>& H, vector<int>& B, int K) {

    // Sort the monsters and sentinels by their x-coordinates
    vector<pair<int, int>> monsters;
    for (int i = 0; i < M; i++) {
        monsters.push_back(make_pair(A[i], H[i]));
    }
    sort(monsters.begin(), monsters.end());

    sort(B.begin(), B.end());

    // Iterate over each sentinel
    for (int i = 0; i < N; i++) {
        int sentinel = B[i];

        // Calculate the maximum and minimum x-coordinate reachable by the sentinel's railgun
        int max_x = sentinel + K;
        int min_x = sentinel - K;

        // Initialize the remaining monsters list
        vector<pair<int, int>> remaining_monsters;

        // Iterate over each monster
        for (auto& monster : monsters) {
            int x = monster.first;
            int health = monster.second;

            // If the monster is within range of the sentinel's railgun, reduce its health
            if (min_x <= x && x <= max_x) {
                health -= K;
            }

            // If the monster is still alive, add it to the remaining monsters list
            if (health > 0) {
                remaining_monsters.push_back(make_pair(x, health));
            }
        }

        // Update the monsters list
        monsters = remaining_monsters;

        // If there are no remaining monsters, return true
        if (monsters.empty()) {
            return true;
        }
    }

    // If there are remaining monsters after iterating over all sentinels, return false
    return false;
}

// int main() {
//     int N, M, K;
//     cin >> N >> M >> K;

//     vector<int> A(M);
//     vector<int> H(M);
//     vector<int> B(N);

//     for (int i = 0; i < M; i++) {
//         cin >> A[i];
//     }

//     for (int i = 0; i < M; i++) {
//         cin >> H[i];
//     }

//     for (int i = 0; i < N; i++) {
//         cin >> B[i];
//     }

//     int result = killAllMonsters(A, H, B, K);
//     cout << result << endl;

//     return 0;
// }

int main() {
    int N = 2;
    int M = 3;
    int K = 5;
    vector<int> A = {2 ,3, 4};
    vector<int> H = {10, 6, 8};
    vector<int> B = {1, 5, 7};

    bool result = can_kill_all_monsters(N, M, A, H, B, K);
    cout << result << endl;  // Output: 1

    return 0;
}

/*
3 3 5
2 3 4
10 6 8
1 5 7

*/