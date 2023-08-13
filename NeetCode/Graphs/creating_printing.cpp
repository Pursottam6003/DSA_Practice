// https://www.codingninjas.com/studio/problems/creating-and-printing_1214551?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> adj(n);

    vector<int> ans[n];

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);
        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}