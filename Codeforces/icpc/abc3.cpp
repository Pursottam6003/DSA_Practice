  

#include <bits/stdc++.h>    
using namespace std;    

bool isValid(int x, int y, int n, int m) {
    // return 0 <= x && x < n && 0 <= y && y < m; 
    return x >= 0 && x < n && y >= 0 && y < m;
}

string minStr = "CCC";

void dfs(int x, int y, vector<vector<bool>>& visited, const vector<string>& grid, string& currentStr) {
    if (visited[x][y] || currentStr.length() == 3) {
        return;
    }

    visited[x][y] = true;
    currentStr += grid[x][y];

    if (currentStr.length() == 3 && currentStr < minStr) {
        minStr = currentStr;
    }

    // Continue the search in all eight directions.
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            if (!isValid(x + dx, y + dy, grid.size(), grid[0].size()) || visited[x + dx][y + dy]) {
                continue;
            }
            if(dx != 0 || dy != 0) {
                dfs(x + dx, y + dy, visited, grid, currentStr);
            }
        }
    }

    // Backtrack.
    visited[x][y] = false;
    currentStr.pop_back();
}
string findSmallestString(vector<string> grid)
{
    string result(3, 'C');
    vector<vector<bool>> visited(3, vector<bool>(3, false));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            string currentStr = "";
            dfs(i, j, visited, grid, currentStr);
        }
    }

    return result;
} 

int main()
{
    vector <string> grid(3);

    for(int i=0;i<3;i++)
        cin>>grid[i];
    
    string ans = findSmallestString(grid);
    cout<<minStr<<endl;
    return 0;
}