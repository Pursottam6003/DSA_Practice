#include <iostream>
#include <vector>

const int MAXN = 100005;

std::vector<int> tree[MAXN]; // Adjacency list representation of the tree
int parent[MAXN];            // Parent array
int depth[MAXN];             // Depth array
int freq[MAXN];              // Frequency of LCA values

void dfs(int node, int parent, int d)
{
    depth[node] = d;
    for (int child : tree[node])
    {
        if (child != parent)
        {
            dfs(child, node, d + 1);
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] > depth[v])
    {
        std::swap(u, v);
    }
    while (depth[v] > depth[u])
    {
        v = parent[v];
    }
    while (u != v)
    {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

std::vector<int> calcPairs(int N, std::vector<int> p)
{
    for (int i = 0; i < N; ++i)
    {
        parent[i] = p[i];
        if (parent[i] != -1)
        {
            tree[parent[i]].push_back(i);
        }
    }

    dfs(0, -1, 0); // Perform DFS traversal to calculate depth

    for (int i = 1; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            int common_ancestor = lca(i, j);
            ++freq[common_ancestor];
        }
    }

    std::vector<int> result;
    for (int x = 1; x < N; ++x)
    {
        result.push_back(freq[x]);
    }

    return result;
}

int main()
{
    int N;
    std::cout << "Enter the value of N: ";
    std::cin >> N;

    std::vector<int> p(N);
    std::cout << "Enter the parent array p:" << std::endl;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> p[i];
    }

    std::vector<int> result = calcPairs(N, p);

    std::cout << "Output list:" << std::endl;
    for (int value : result)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        // ans[0].push_back(i);
        ans[edges[i][0]].push_back(edges[i][1]);
        ans[edges[i][1]].push_back(edges[i][0]);
    }
    return ans;
}