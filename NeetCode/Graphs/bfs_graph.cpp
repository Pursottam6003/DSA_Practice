// https://takeuforward.org/graph/breadth-first-search-bfs-level-order-traversal/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here

        vector<int> vis(V, 0);
        vector<int> res;

        queue<int> que;

        // mark the first node as visited
        vis[0] = 1;
        // insert the first element into the queu
        que.push(0);

        while (!que.empty())
        {
            int node = que.front();

            res.push_back(node);
            que.pop();

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    // make it visited
                    vis[it] = 1;
                    que.push(it);
                }
            }
        }

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    // Write your code here.

    // make a queue
    queue<int> que;

    // create a vector to store ther final res
    vector<int> res;

    // create a vector to keep the track of visited elements during traversal

    vector<int> vis(n, 0);

    // push the first element into queu as starigint ndoe as 0
    que.push(0);
    vis[0] = 1; // set the first node

    while (!que.empty())
    {
        int nodes = que.front();

        // push the current node into the vector res
        res.push_back(nodes);

        // pop the element from the que
        que.pop();

        for (auto it : adj[nodes])
        {
            // mark it visited as empty
            if (!vis[it])
            {
                vis[it] = 1;
                que.push(it);
            }
        }
    }

    return res;
}