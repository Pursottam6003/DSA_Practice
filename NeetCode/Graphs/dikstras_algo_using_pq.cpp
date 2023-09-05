vector<int> dijkstra(vector<vector<int>> &edge, int v, int e, int source)
{
    // Write your code here.
    // 'edge' contains {u, v, distance} vectors.

    // convert the vector into adj list
    vector<pair<int, int>> adj[v];

    for (int i = 0; i < e; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // dist node

    // push the src with dist 0 in pq
    vector<int> dist(v, INT_MAX);

    dist[source] = 0;

    pq.push({0, source});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int w = it.second;

            if (w + dis < dist[v])
            {
                // update the dist matrix
                dist[v] = w + dis;
                // push the new one into queue
                pq.push({w + dis, v});
            }
        }
    }
    return dist;
}