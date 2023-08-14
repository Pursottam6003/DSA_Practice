void traverse(int idx, vector<vector<int>> &roads, vector<int> &visited)
{
    for (int i = 0; i < roads.size(); i++)
    { // if the roads[idx][i] exists  and it is not visited ye
        if (roads[idx][i] == 1 && visited[i] == 0 && idx != i)
        {
            visited[i] = 1;
            traverse(i, roads, visited);
        }
    }
}
int findNumOfProvinces(vector<vector<int>> &roads, int n)
{
    // Write your code here.

    int res = 0;
    // create a vector to keep the track of visited elements
    vector<int> visited(n, 0);

    // iterate over the loop
    for (int i = 0; i < n; i++)
    {                        // check if visited is not one
        if (visited[i] == 0) // (!visited[i]=0)
        {
            // traverse the graph  from i th node
            traverse(i, roads, visited);
            // increment thr res
            res++;
        }
    }
    return res;
}