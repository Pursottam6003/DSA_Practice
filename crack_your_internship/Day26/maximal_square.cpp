// https://leetcode.com/problems/maximal-square/submissions/
class Solution {
public:

    int maximalSquare(vector<vector<char>>& matrix) {
        
        int r=matrix.size();
        if(r ==0 ) return 0;

        int c = (r>0) ? matrix[0].size() : 0;

        vector <vector<int>> dp(r+1,vector<int>(c+1,0));

        int largest_area=0;

        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {   // process all the data
                    // left right diagronal
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));

                    largest_area =max(dp[i][j],largest_area);
                }
            }
        }
        // square 
        return largest_area*largest_area;
    }
};