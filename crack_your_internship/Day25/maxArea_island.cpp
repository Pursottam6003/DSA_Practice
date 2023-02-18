// https://leetcode.com/problems/max-area-of-island/submissions/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {   int ct=1;
                    
                    dfs(grid,i,j,ct);
                    maxArea = max(ct,maxArea);
                }
            }
        }
        return maxArea;
    }

    int dfs(vector <vector <int>> &grid,int i ,int j ,int &ct)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()){
            return 0;
        }
        
        //check if it is a useless neighbour, return 0 if it is useless
        if(grid[i][j]==0) return 0;
        
        
        //after backtracking make neighbour 0 so that it will not interfare in further iterations
            grid[i][j]=0;
            //call the neighbours if they are helpful or not


        if(dfs(grid,i-1,j,ct) ==1) ct++;
        if(dfs(grid,i,j-1,ct) ==1) ct++;
        if(dfs(grid,i+1,j,ct) ==1) ct++;
        if(dfs(grid,i,j+1,ct) ==1 ) ct++;

        return 1;
    }
};