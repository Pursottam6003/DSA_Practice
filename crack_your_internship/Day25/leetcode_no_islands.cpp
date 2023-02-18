// https://leetcode.com/problems/number-of-islands/description/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size(),n = grid[0].size(),ct=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    ct++;
                    //chcek for neighbours
                    dfs(grid,i,j);
                }
            }
        }
        return ct;
    }

    void dfs(vector <vector <char>> &grid,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0'){
          return;
      }
        grid[i][j] ='0';
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }
};