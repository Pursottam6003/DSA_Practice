class Solution
{
public:
    void dfs(int idx, vector<vector<int>> &adj, vector<int> &vis)
    {

        for (int i = 0; i < adj[idx].size(); i++)
        {
            if (adj[idx][i] == 1 && vis[i] == 0 && idx != i)
            {
                vis[i] = 1;
                dfs(i, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int res = 0;
        int n = isConnected.size();

        vector<int> vis(n, 0);
        // make the first visited node as 1
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, isConnected, vis);
                res++;
            }
        }
        return res;
    }
};