#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() { 
    vector<vector<char>> grid(3, vector<char>(3));

// Input grid
for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        cin >> grid[i][j];
    }
}

string smallest_word = "ABC";  // Initialize with lexicographically largest word

// Iterate through all triples of adjacent cells
for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int ni = i + dx;
                int nj = j + dy;

                if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3 && (i != ni || j != nj)) {
                    // Check for another adjacent cell that is not the current cell or the first adjacent cell
                    for (int dx2 = -1; dx2 <= 1; ++dx2) {
                        for (int dy2 = -1; dy2 <= 1; ++dy2) {
                            int ni2 = i + dx2;
                            int nj2 = j + dy2;

                            if (ni2 >= 0 && ni2 < 3 && nj2 >= 0 && nj2 < 3 && (i != ni2 || j != nj2) && (ni != ni2 || nj != nj2)) {
                                string current_word = {grid[i][j], grid[ni][nj], grid[ni2][nj2]};
                                sort(current_word.begin(), current_word.end());

                                if (current_word < smallest_word) {
                                    smallest_word = current_word;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

cout << smallest_word << endl;

return 0;
}
