#include <bits/stdc++.h>
using namespace std;

int answer = -1;
void dfs(int node, vector<int> &edges, unordered_map<int, int> &dist, vector<bool> &vis)
{
    vis[node] = true;

    int adjNode = edges[node];

    if (adjNode != -1 && !vis[adjNode])
    {
        dist[adjNode] = dist[node] + 1;
        dfs(adjNode, edges, dist, vis);
    }
    else if (adjNode != -1 && dist.count(adjNode))
    {
        answer = max(answer, dist[node] - dist[adjNode] + 1);
    }
}
int longestCycle(vector<int> &edges)
{

    int n = edges.size();
    vector<bool> vis(n);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            unordered_map<int, int> dist;
            dist[i] = 1;

            dfs(i, edges, dist, vis);
        }
    }

    return answer;
}
int main()
{
    int N;
    cin >> N;

    vector<int> edges(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> edges[i];
    }

    cout << longestCycle(edges) << endl;
}