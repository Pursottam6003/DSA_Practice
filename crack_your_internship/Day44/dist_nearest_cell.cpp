// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
       //Function to find distance of nearest 1 in the grid for each cell.
    /*
    Hello everyone this is a standerd bfs question as this question asks for
    minimum distance from 1. To solve this question we need to follow thease steps.
    
     1.Take all 1's as the base level like a root of tree.
     2.Now make a answer matrix and initialize with -1.
     3.Find all 1 and push it to queue and update its distance to 0 in the answer matrix.
     4.Now traverse to all child of the 1's if the answer[i][j] of the child is -1 then update
     the answer by adding 1 to the distance of its parent.
     5.Finally return the answer matrix
     
     Similar question:
     Rotten oranges
     Knight Walk
     
     Upvote if you like!!
    */
 
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code 
	    
	    int r = grid.size();
	    int c = grid[0].size();
	    
	    // ans vector 
	    vector <vector<int>> ans(r,vector<int> (c,-1));
	    
	    // taking a queue of type pair to store roa and col details
	    queue <pair<int,int>> que;
	    
	    // now traverse the answer matrix
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            if(grid[i][j] ==1)
	            {
	                // push into queue
	                que.push({i,j});
	                // make the grid[i][j] as 0
	                // since distance from itself would be 0
	                ans[i][j]=0;
	               
	            }
	        }
	    }
	    
	    // now traversing the que 
	    
	    // 4 condiciont of checking left right top bottom 
	    
	    int dx[] = {0,0,1,-1};
	    int dy[] = {1,-1,0,0};
	    
	    int level =0;
	   	while(!que.empty())
	    {
	        int size = que.size();
	        for(int i=0;i<size;i++) {
	            int a = que.front().first;
	            int b = que.front().second;
	            que.pop();
	            
	            for(int k=0;k<4;k++)
	            {
	                int na = a+dx[k];
	                int nb = b+dy[k];
	                
	                if(na<0||nb<0||na>=r||nb>=c||ans[na][nb]!=-1) continue;
	                que.push({na,nb});
	                ans[na][nb]=ans[a][b]+1;
	            }
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends