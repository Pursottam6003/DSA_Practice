class Solution {
public:
    /**
     * @param S: a string
     * @param T: a string
     * @return: the minimum substring of S
     */
    string minWindow(string &S, string &T) {
        // Write your code here
        //std::vector<vector<vector<bool>>> dp( S.size()+1, vector<vector<bool>>(S.size()+1,  vector<bool>(T.size()+1, false)) ) ;
        vector<vector<int>> dp( S.size()+1, vector<int>(T.size()+1, -1) ); // start pos
        int min_len = INT_MAX;
        string ans; 
        
        for( int i=0; i<=S.size(); i++ )
            dp[i][0] = i+1;
        
        for( int i=1; i<=S.size(); i++ )
        {
            for( int k=1; k<=min(i,(int)T.size()); k++ )
            {
                if( S[i-1] == T[k-1] )
                    dp[i][k] = dp[i-1][k-1];
                else
                    dp[i][k] = dp[i-1][k];
            }
            if( dp[i][T.size()] != -1  && (i-dp[i][T.size()]+1) < min_len )
            {
                min_len = (i-dp[i][T.size()]+1);
                ans = S.substr(dp[i][T.size()]-1, (i-dp[i][T.size()]+1));
            }
        }
        return ans;
    }
};