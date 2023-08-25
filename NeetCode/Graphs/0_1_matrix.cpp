/// @brief https://leetcode.com/problems/01-matrix/description/
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> que;

        // populate into the que

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    que.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        while (!que.empty())
        {
            int row = que.front().first.first;
            int col = que.front().first.second;
            int distance = que.front().second;

            dist[row][col] = distance;

            que.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    dist[nrow][ncol] = distance;
                    que.push({{nrow, ncol}, distance + 1});
                }
            }
        }

        return dist;
    }
};