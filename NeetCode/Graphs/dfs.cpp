// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.

    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &res)
    {
        vis[node] = 1;
        res.push_back(node);
        // traverse all its neighbours
        for (auto it : adj[node])
        {
            // if the neighbour is not visited
            if (!vis[it])
            {
                dfs(it, adj, vis, res);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here

        vector<int> vis(V, 0);

        int start = 0;

        vector<int> res;

        dfs(start, adj, vis, res);
        return res;
    }
};