// https://leetcode.com/problems/count-sub-islands/submissions/900338112/
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int m = grid1.size(), n = grid1[0].size(),res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid2[i][j] ==1) 
                    res += dfs(grid1,grid2,i,j);
            }
        }
        return res;
    }

    int dfs(vector <vector<int>> &grid1,vector <vector<int>> &grid2,int i,int j)
    {
        int m = grid1.size(),n = grid1[0].size(),res=1;

        if(i <0 || i ==m || j <0 || j==n || grid2[i][j]==0) return 1;

        // make it zero
        grid2[i][j]=0;
        res &= dfs(grid1,grid2,i-1,j);
        res &= dfs(grid1,grid2,i+1,j);
        res &= dfs(grid1,grid2,i,j-1);
        res &= dfs(grid1,grid2,i,j+1);

        return res & grid1[i][j];
    }
};