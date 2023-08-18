#include <bits/stdc++.h>
using namespace std;

vector<int> shortPath(vector<int> adj[], int c1, int n)
{

    vector<int> dist(n, INT_MAX);
    queue<int> q;
    q.push(c1);
    dist[c1] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
int main()
{
    int n;
    cin >> n;

    vector<int> edges(n);
    for (int i = 0; i < n; i++)
        cin >> edges[i];

    int c1, c2;
    cin >> c1 >> c2;
    // created a vector of size n as adjancy list

    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        if (edges[i] == -1)
            continue;
        adj[i].push_back(edges[i]);
    }
    // call the short path
    vector<int> v1 = shortPath(adj, c1, n);
    vector<int> v2 = shortPath(adj, c2, n);

    int mn = INT_MAX, node = -1;
    for (int i = 0; i < n; i++)
    {
        if (v1[i] == INT_MAX || v2[i] == INT_MAX)
            continue;
        if (v1[i] + v2[i] < mn)
        {
            mn = v1[i] + v2[i];
            node = i;
        }
    }
    cout << node << endl;
    return 0;
}