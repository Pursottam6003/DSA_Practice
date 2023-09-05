// https://leetcode.com/problems/course-schedule-ii/
#include <bits/stdc++.h>

vector<int> findSchedule(int numCourses, vector<pair<int, int>> &prerequisites)
{

    vector<int> adj[numCourses + 1];
    vector<int> indegree(numCourses + 1, 0);

    for (auto it : prerequisites)
    {

        int u = it.first;
        int v = it.second;
        adj[u].push_back(v);
    }
    queue<int> que;

    for (int i = 0; i <= numCourses; i++)
    {
        for (int it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i <= numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            que.push(i);
        }
    }
    vector<int> res;

    while (!que.empty())
    {
        int node = que.front();

        que.pop();
        res.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;

            if (indegree[it] == 0)
            {
                que.push(it);
            }
        }
    }

    if (res.size() != numCourses)
        return {};

    return res;
}

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {

        int V = numCourses;
        vector<int> adj[V];

        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        if (topo.size() == V)
        {
            return topo;
        }
        return {};
    }
};