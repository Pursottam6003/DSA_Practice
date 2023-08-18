// https://leetcode.com/problems/flood-fill/
class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int ini_color, int new_col)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == new_col || grid[i][j] != ini_color)
        {
            return;
        }

        grid[i][j] = new_col;
        dfs(grid, i - 1, j, ini_color, new_col);
        dfs(grid, i, j + 1, ini_color, new_col);
        dfs(grid, i + 1, j, ini_color, new_col);
        dfs(grid, i, j - 1, ini_color, new_col);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        vector<vector<int>> grid = image;
        int ini_col = grid[sr][sc];

        dfs(grid, sr, sc, ini_col, color);
        return grid;
    }
};