class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        // 2d visited array
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> que;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    que.push({{i, j}, 0});
                    // make that in visited array
                    vis[i][j] = 2;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int tm = 0;

        // applying bfs algorithm
        while (!que.empty())
        {
            auto it = que.front();

            int r = it.first.first;
            int c = it.first.second;
            int t = it.second;

            tm = max(tm, t);
            que.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // checking validity

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    que.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2; // maked it rotten
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // if it is unsucessful to make every fresh oranges rotten
                // return -1
                if (vis[i][j] != 2 && grid[i][j] == 1)
                    return -1;
            }
        }

        return tm;
    }
};