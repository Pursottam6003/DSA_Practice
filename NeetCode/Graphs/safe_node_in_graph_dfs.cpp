#include <bits/stdc++.h>

bool detect_cycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis, int checkNode[])
{
    vis[node] = 1;
    pathVis[node] = 1;
    checkNode[node] = 0;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (detect_cycle(it, adj, vis, pathVis, checkNode) == true)
            {
                checkNode[node] = 0;
                return true;
            }
        }

        else if (pathVis[it])
        {
            checkNode[node] = 0;
            return true;
        }
    }
    pathVis[node] = 0;
    checkNode[node] = 1;
    return false;
}

vector<int> safeNodes(vector<vector<int>> &edges, int n, int e)
{
    // Write your code here.
    vector<int> adj[n + 1];

    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<int> res;

    vector<int> vis(n + 1, 0);
    vector<int> pathVis(n + 1, 0);
    int checkNode[n + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            detect_cycle(i, adj, vis, pathVis, checkNode);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (checkNode[i] == 1)
        {
            res.push_back(i);
        }
    }

    return res;
}