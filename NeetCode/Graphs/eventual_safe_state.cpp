// https://leetcode.com/problems/find-eventual-safe-states/description/
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        int n = graph.size();
        // create an adjancy list
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
            {
                adj[it].push_back(i);
            }
        }

        // now check the no of inorder traversal
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> que;

        vector<int> topo;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
            }
        }

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

        sort(topo.begin(), topo.end());
        return topo;
    }
};