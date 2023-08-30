// https://www.codingninjas.com/studio/problems/topological-sorting_973003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <bits/stdc++.h>

void dfs(int node, vector<int> adj[], stack<int> &stk, vector<int> &vis)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, stk, vis);
        }
    }

    stk.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{
    // Write your code here!
    vector<int> adj[nodes];

    for (int i = 0; i < graph.size(); i++)
    {
        adj[graph[i][0]].push_back(graph[i][1]);
    }

    vector<int> vis(nodes, 0);
    vector<int> res;

    stack<int> stk;

    for (int i = 0; i < nodes; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, stk, vis);
        }
    }

    while (!stk.empty())
    {
        res.push_back(stk.top());
        stk.pop();
    }

    return res;
}
