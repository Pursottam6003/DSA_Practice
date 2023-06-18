#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int minimumCostGathering(int N, const vector<int>& weightArr) {
    int minCost = INT_MAX;
    int totalCost = 0;
    int sumWeights = 0;

    // Calculate the sum of weights and initial cost assuming k = 0
    for (int i = 0; i < N; ++i) {
        sumWeights += weightArr[i];
        totalCost += weightArr[i] * i;
    }

    minCost = totalCost; // Set the initial minimum cost

    for (int k = 1; k < N; ++k) {
        // Update the total cost by subtracting the sum of weights and adding the (N - sumWeights)
        totalCost += (N - sumWeights);
        
        // Update the minimum cost if the current total cost is smaller
        minCost = min(minCost, totalCost);
        
        // Update the sum of weights by subtracting the weight at index (k-1) and adding the weight at index (k+N-1)
        sumWeights = sumWeights - weightArr[k - 1] + weightArr[k + N - 1];
    }

    return minCost;
}

int main() {
    int N = 5;
    vector<int> weightArr = {1, 4, 5, 2, 10};
    int result = minimumCostGathering(N, weightArr);
    cout << result << endl;

    return 0;
}
