// https://leetcode.com/problems/word-search
class Solution {
public:

    bool DFS(vector <vector <char >> &board,string word,int i,int j,int n)
    {
        // check if all the alphabets in tthe word is checked
        if(n==word.size()) return true;

        // check if i and j are out of bound or if the characters are not ewual
    if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n]) return false;

        // mark as visited 
        board[i][j] = '0';

        // branch ou in all 4 directions
        bool status = DFS(board,word,i+1,j,n+1) || // down 
        DFS(board,word,i,j+1,n+1) || // right 
        DFS(board,word,i,j-1,n+1) || // left 
        DFS(board,word,i-1,j,n+1); // up 
        // change the character back for other searches 
        board[i][j] = word[n];
        return status;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        /*
        vector <int> words(26,0); // initialized with 0   
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {   
                words[toupper(board[i][j])-'A']++;
            }
        }
        
        for(int i=0;i<word.size();i++)
        {
            if(words[toupper(word[i])-'A'] <=0) return false; 
            words[toupper(word[i])-'A']--;
        }
        */

        // if the word is empty 
        if(word == "") return false;

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                // check if the characters are equal then call DFS
                 if(board[i][j] == word[0] && DFS(board, word, i, j, 0))
                    return true;
            }
        }
        
    
        return false;
    }
};