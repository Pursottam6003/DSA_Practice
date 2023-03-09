//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool isValid(int x,int y ,int row,int col)
    {
        if(x < 0 || y < 0 || x>=row || y >= col) return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        // create row and col variablles
        int r = grid.size();
        int c = grid[0].size();
        int t =0,fresh=0;
        
        queue <pair<int,int>> que;
        
        // i guess when we want only rotten oranges side
        
        for(int i=0;i<r;i++)
        {
            for(int j = 0;j<c;j++)
            {
                if(grid[i][j] ==2)
                {
                    // if it rotten then we need to finid the other sides 
                    que.push({i,j});
                }
                
                else if(grid[i][j] == 1) fresh++;
            }
        }
        
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1 , 0, -1, 0};
        
        
        
        while(!que.empty())
        {
            t++; // incrementing time
            int size = que.size();
        
            for(int i =0;i<size;i++)
            {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                
                for(int j=0;j<4;j++)
                {
                    int xdx = x + dx[j];
                    int ydy = y + dy[j];
                    
                    if(isValid(xdx,ydy,r,c) && grid[xdx][ydy] ==1)
                    {
                        grid[xdx][ydy] = 2; // making it rotten 
                        fresh --; //decrementing fresh 
                        que.push({xdx,ydy});
                    }
                }
            }
            
            if(fresh ==0) return t;
        }
        
        return -1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends