class Solution {
public:
    

int prime = 1e9+7;


int subsequenceCounting(string &s1, string &s2, int n, int m) {
    // Write your code here.
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<m+1;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            
            if(s1[i-1]==s2[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime;
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    
    return dp[n][m];
} 

    int numDistinct(string s, string t) {
       

        if(s.size()==0 || t.size()==0) return 0;
        return  subsequenceCounting(s,t,s.size(),t.size());
    
    }
};