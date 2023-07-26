// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
class Solution
{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int node, int col, int n, int *color, bool graph[101][101])
    {
        for (int k = 0; k < n; k++)
        {
            if (k != node && graph[k][node] == 1 && color[k] == col)
            {
                return false;
            }
        }
        return true;
    }
    bool recur(int ind, int m, int n, bool graph[][101], int *color)
    {
        // base case
        if (ind == n)
            return true;
        for (int i = 1; i <= m; i++)
        {
            // choose a color from m pallets
            // make it visited

            if (isSafe(ind, i, n, color, graph))
            {
                // then it make it visited
                color[ind] = i;
                if (recur(ind + 1, m, n, graph, color))
                    return true;
                color[ind] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        // your code here

        int color[n] = {0};

        if (recur(0, m, n, graph, color))
            return true;
        return false;
    }
};