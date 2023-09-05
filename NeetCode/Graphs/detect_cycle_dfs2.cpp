bool dfs(int node, vector<int> adj[], vector<int> &Visit, vector<int> pathVisit)
{
    Visit[node] = 1;
    pathVisit[node] = 1;
    for (auto nbr : adj[node])
    {
        if (!Visit[nbr])
        {
            if (dfs(nbr, adj, Visit, pathVisit))
                return true;
        }
        else if (pathVisit[nbr])
            return true;
    }
    pathVisit[node] = 0;
    return false;
}
bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    vector<int> pathVisit(v, 0);
    vector<int> Visit(v, 0);
    vector<int> adj[v];

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    for (int i = 0; i < v; i++)
    {
        if (!Visit[i])
        {
            if (dfs(i, adj, Visit, pathVisit))
                return true;
        }
    }
    return false;
}