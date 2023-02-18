// https://leetcode.com/problems/surrounded-regions/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        if ( board.size() == 0)
            return;
        int rows = board.size();
        int cols = board[0].size();

        // check first and last col
    
        for(int i=0;i<rows;i++)
        {
            if(board[i][0] =='O') dfs(board,i,1);

            if(board[i][cols-1] =='O') dfs(board,i,cols-2); 
        }

    
        // check first and last row
    
        for(int i=0;i<cols;i++)
        {
            if(board[0][i] =='O') dfs(board,1,i);

            if(board[rows-1][i] =='O') dfs(board,rows-2,i); 
        }

        // flip O to X , * to O 
        // skip the boundries 
        for(int i=1;i<rows-1;i++)
        {
            for(int j=1;j<cols-1;j++)
            {
                if(board[i][j] =='*')
                    board[i][j] ='O';
                
                else if(board[i][j]=='O')
                    board[i][j] ='X';
            }
        }
    }

private:
    void dfs(vector <vector<char>> &board,int i,int j)
    {
        if(i<=0 || i >=board.size()-1 || j <=0 || j>= board[0].size()-1 || board[i][j]=='X') return ; // normal dfs algo

        if(board[i][j] =='*') return ;
        if(board[i][j] =='O') 
        {
            board[i][j]='*';
        }
        dfs(board,i+1,j);
        dfs(board,i,j+1);
        dfs(board,i-1,j);
        dfs(board,i,j-1);
    }
};