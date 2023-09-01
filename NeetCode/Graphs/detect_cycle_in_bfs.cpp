#include <bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  int res=0;
  vector <int> topo;
  vector <int> adj[n+1];

  for(auto it: edges)
  { 
      int u = it.first;
      int v = it.second;
      adj[u].push_back(v);
  }
  

  queue <int> q;

  vector <int> indegree(n+1,0);

  for(int i=0;i<n+1;i++)
  { 
    for(auto it: adj[i])
    {
      indegree[it]++;
    }
  }

  for(int i=0;i<n+1;i++) {

    if (indegree[i] == 0) {
      q.push(i);
    
    }
  }
  while(!q.empty())
  {
    int todo = q.front();
    topo.push_back(todo);
    q.pop();
    for(auto it: adj[todo])
    {
      indegree[it]--;
      if(indegree[it]==0)
      {
        q.push(it);
      }
    }
  }


  if(topo.size() !=n+1) return 1;

  return 0;
}