#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(int x, int y) {
    return 0 <= x && x < 3 && 0 <= y && y < 3;
}

void dfs(int x, int y, vector<vector<bool>>& visited, const vector<vector<char>>& grid, string& currentStr, string& result) {
    if (!isValid(x, y) || visited[x][y]) {
        return;
    }

    visited[x][y] = true;
    currentStr += grid[x][y];

    if (currentStr.length() == 9) {
        result = min(result, currentStr);
        visited[x][y] = false;
        return;
    }

    int directions[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}, {0, 0}};

    for (int i = 0; i < 9; ++i) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        dfs(nx, ny, visited, grid, currentStr, result);
    }

    visited[x][y] = false;
}

string findLexicographicallySmallest(const vector<vector<char>>& grid) {
    string result = string(9, ' ');
    vector<vector<bool>> visited(3, vector<bool>(3, false));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            string currentStr = "";
            dfs(i, j, visited, grid, currentStr, result);
        }
    }

    return result;
}

int main() {
    vector<vector<char>> grid = {
        {'A', 'B', 'C'},
        {'B', 'A', 'B'},
        {'C', 'C', 'A'}
    };

    string smallestString = findLexicographicallySmallest(grid);
    cout << "Lexicographically Smallest String: " << smallestString << endl;

    return 0;
}
