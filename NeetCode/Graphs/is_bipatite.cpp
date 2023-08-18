
// dfs approach
// coding ninjas one
bool dfs(int v, int c, vector<int> &color, vector<vector<int>> &edges)
{

    color[v] = c;

    int nc = (c == 0) ? 1 : 0;

    for (int i = 0; i < edges.size(); i++)
    {

        if (edges[v][i] == 1)
        {

            if (color[i] == -1)
            {

                dfs(i, nc, color, edges);
            }
            else
            {

                if (color[i] == c)
                    return false;
            }
        }
    }

    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{

    vector<int> color(edges.size(), -1);

    for (int i = 0; i < edges.size(); i++)
    {

        if (color[i] == -1)
        {

            if (!dfs(i, 0, color, edges))
                return false;
        }
    }

    return true;

    // Write your code here.
}

// leetcode one
class Solution
{
public:
    bool dfs(int node, int col, int *colors, vector<vector<int>> &graph)
    {
        colors[node] = col;

        // traverse adjacent nodes

        for (auto it : graph[node])
        {
            if (colors[it] == -1)
            {
                if (dfs(it, !col, colors, graph) == false)
                    return false;
            }
            else if (colors[it] == col)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {

        int n = graph.size();
        int colors[n];

        for (int i = 0; i < n; i++)
            colors[i] = -1;
        // fo connected components

        for (int i = 0; i < n; i++)
        {
            if (colors[i] == -1)
            {
                if (dfs(i, 0, colors, graph) == false)
                    return false;
            }
        }
        return true;
    }
};

// bfs approach

#include <bits/stdc++.h>
bool isGraphBirpatite(vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> adj(edges.size());
    for (int i = 0; i < edges.size(); i++)
    {
        for (int j = 0; j < edges[0].size(); j++)
        {
            if (edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> color(edges.size(), 0);
    queue<int> q;
    color[0] = 1;
    q.push(0);
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        for (auto child : adj[f])
        {
            if (color[child] == 0)
            {
                color[child] = ~color[f];
                q.push(child);
            }
            else if (color[child] == color[f])
                return false;
        }
    }
    return true;
}
