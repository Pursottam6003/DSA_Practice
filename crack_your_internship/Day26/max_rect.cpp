
// https://leetcode.com/problems/maximal-rectangle/description/
/*

last test case was wrong approach is easy btw 

class Solution {
public:

    int historgram(vector <char> &vec,int n)
    {
        // declaring a stack 
        stack <int> stk;
        int res=0,curr=0,tp=0;

        for(int i=0;i<n;i++)
        {
            // condition for while loop 
            while(!stk.empty() && (vec[stk.top()]-'0') > (vec[i]-'0'))
            {
                // do something
                tp = stk.top();
                // popp the element
                stk.pop();
                // if stack is empty multiply with i
                // othewise multiply with 
                curr = (vec[tp]-'0') * (stk.empty() ? i : i-stk.top()-1);
                // returning the result
                res = max(res,curr);
            }
            stk.push(i); // pusing the index
        }

        while(!stk.empty())
        {
            // still if something remaingin then 
            tp = stk.top();
            stk.pop();
            curr = (vec[tp]-'0') * ((stk.empty()) ? n : (n-stk.top()-1));
            res = max(res,curr);
        }
        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        int res = historgram(matrix[0],n);

        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j] =='1') 
                {
                    int temp = (matrix[i-1][j]-'0')+1;

                    matrix[i][j] = temp+'0';
                }
            }
            res = max(res,historgram(matrix[i],n));
        } 

        return res;   

    }
};
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& M) {
        if(!size(M)) return 0;
        int ans = 0, m = size(M), n = size(M[0]);
        vector<vector<short>> dp(m+1, vector<short>(n+1)), up(m, vector<short>(n,1)), down(up);
        for(int i = m-1; ~i; i--) 
            for(int j = n-1; ~j; j--) 
                dp[i][j] = M[i][j] == '1' ? dp[i][j+1] + 1 : 0;
        
        stack<int> s;
        for(int j = 0; j < n; j++) {
            s = stack<int>();
            for(int i = 0; i < m; i++) {
                while(size(s) && dp[s.top()][j] >= dp[i][j]) s.pop();
                up[i][j] = i - (size(s) ? s.top() : -1);
                s.push(i);
            }
            s = stack<int>();
            for(int i = m-1; ~i; i--) {
                while(size(s) && dp[s.top()][j] >= dp[i][j]) s.pop();
                down[i][j] = (size(s) ? s.top() : m) - i;
                s.push(i);
            }            
        }

        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                ans = max(ans, dp[i][j] * (up[i][j]+down[i][j]-1));
                    
        return ans;
    }
};