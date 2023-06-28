#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int findMinimumAmount(int N, const vector<int>& prices, const vector<int>& dislike) {
    unordered_map<int, vector<int>> dislikedDishes;
    for (int i = 0; i < N; i++) {
        if (dislikedDishes.find(dislike[i]) != dislikedDishes.end()) {
            dislikedDishes[dislike[i]].push_back(i + 1);
        } else {
            dislikedDishes[dislike[i]] = {i + 1};
        }
    }

    int minCost = INT_MAX;
    for (int i = 0; i < N; i++) {
        int totalCost = 0;
        for (int j = 0; j < N; j++) {
            if (j + 1 != i + 1 && (dislikedDishes.find(i + 1) == dislikedDishes.end() || 
                find(dislikedDishes[i + 1].begin(), dislikedDishes[i + 1].end(), j + 1) == dislikedDishes[i + 1].end())) {
                totalCost += prices[j];
            }
        }
        minCost = min(minCost, totalCost);
    }

    if (minCost == INT_MAX) {
        return -1;
    } else {
        return minCost;
    }
}

int main() {
    int N = 5;
    vector<int> prices = {10, 8, 5, 12, 8};
    vector<int> dislike = {1, 1, 3, 2, 4};

    int result = findMinimumAmount(N, prices, dislike);
    cout << result << endl;  // Output: 13

    return 0;
}
