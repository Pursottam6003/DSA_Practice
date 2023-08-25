
// https://leetcode.com/problems/number-of-enclaves/description/
class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {

        queue<pair<int, int>> que;
        int n = grid.size();

        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // traverse boundary elements

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        que.push({i, j});
                        vis[i][j] = 1; // make it visited
                    }
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!que.empty())
        {
            int r = que.front().first;
            int c = que.front().second;

            que.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow, ncol;
                nrow = r + drow[i];
                ncol = c + dcol[i];

                // check the condition of feasiblity
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    // avi bhi
                    if (grid[nrow][ncol] == 1 && vis[nrow][ncol] != 1)
                    {
                        que.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                {
                    res++;
                }
            }
        }

        return res;
    }
};