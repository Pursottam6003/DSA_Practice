// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
//{ Driver Code Starts
/**
     int numIslands(vector<vector<char>>& A) {
        int m = A.size(), n = A[0].size(), res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res += dfs(A, i, j);
        return res;
    }

    int dfs(vector<vector<char>>& A, int i, int j) {
        int m = A.size(), n = A[0].size();
        if (i < 0 || i == m || j < 0 || j == n || A[i][j] == '0') return 0;
        A[i][j] = '0';
        dfs(A, i - 1, j);
        dfs(A, i + 1, j);
        dfs(A, i, j - 1);
        dfs(A, i, j + 1);
        return 1;
    }

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int ct=0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    ct++;
                    dfs(grid,i,j);
                }
            }
        }
        return ct;
        
    }
    
    private:
    void dfs(vector <vector<char>> &grid,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0'){
          return;
      }        
        // otherwise change with 
        grid[i][j] ='0'; // traversed 
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
        dfs(grid,i+1,j+1);
        dfs(grid,i-1,j+1);
        dfs(grid,i+1,j-1);
        dfs(grid,i-1,j-1);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends