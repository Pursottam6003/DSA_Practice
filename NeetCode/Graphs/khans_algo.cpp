#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{
    vector<int> adj[nodes];

    for (int i = 0; i < graph.size(); i++)
    {
        adj[graph[i][0]].push_back(graph[i][1]);
    }

    int indegree[nodes] = {0};
    for (int i = 0; i < nodes; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> que;
    for (int i = 0; i < nodes; i++)
    {
        if (indegree[i] == 0)
        {
            que.push(i);
        }
    }

    vector<int> topo;

    while (!que.empty())
    {
        int node = que.front();
        que.pop();

        topo.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                que.push(it);
            }
        }
    }
    return topo;
}