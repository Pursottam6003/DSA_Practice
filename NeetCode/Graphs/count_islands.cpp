//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &temp, int start, int end, int n, int m)
    {

        vis[row][col] = 1;

        queue<pair<int, int>> q;

        q.push({row, col});

        temp.push_back({row - start, col - end});

        int drow[] = {-1, 0, 1, 0};

        int dcol[] = {0, 1, 0, -1};

        while (!q.empty())
        {

            int r = q.front().first;

            int c = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++)
            {

                int nrow = r + drow[i];

                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {

                    vis[nrow][ncol] = 1;

                    q.push({nrow, ncol});

                    temp.push_back({nrow - start, ncol - end});
                }
            }
        }
    }

    int countDistinctIslands(vector<vector<int>> &arr)
    {

        // Write your code here
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        set<vector<pair<int, int>>> st;

        int count = 0;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                if (!vis[i][j] && arr[i][j])
                {

                    vector<pair<int, int>> temp;

                    bfs(i, j, vis, arr, temp, i, j, n, m);

                    st.insert(temp);
                }
            }
        }

        return st.size();
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends

// User function Template for C++
/// dfs solution
class Solution
{
public:
    void dfs(int r, int c, int m, int n, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &v)
    {

        if (r < 0 || c < 0 || r >= m || c >= n || vis[r][c] || grid[r][c] == 0)
        {
            return;
        }

        v.push_back({r, c});
        vis[r][c] = 1;

        dfs(r + 1, c, m, n, vis, grid, v);
        dfs(r - 1, c, m, n, vis, grid, v);
        dfs(r, c + 1, m, n, vis, grid, v);
        dfs(r, c - 1, m, n, vis, grid, v);
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        set<vector<pair<int, int>>> s;

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (!vis[r][c] && grid[r][c] == 1)
                {
                    vector<pair<int, int>> v;
                    dfs(r, c, m, n, vis, grid, v);
                    auto t = v[0];
                    for (auto &it : v)
                    {
                        it.first -= t.first;
                        it.second -= t.second;
                    }
                    if (s.find(v) == s.end())
                    {
                        s.insert(v);
                    }
                }
            }
        }
        return s.size();
    }
};