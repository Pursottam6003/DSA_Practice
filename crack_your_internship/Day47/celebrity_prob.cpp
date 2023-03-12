// https://www.geeksforgeeks.org/the-celebrity-problem/
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        // creating a stack
        stack <int> stk;
        for(int i=0;i<n;i++)
        {   // pushing all the elements into stack
            stk.push(i);
        }
        
        int x,y;
        
        int idx=0;
        while(stk.size() >=2)
        {   
            x = stk.top();
            stk.pop();
            y = stk.top();
            stk.pop();
            
            
            if(M[x][y] ==1)
            {
                stk.push(y);
            }
            
            else 
            {
                stk.push(x);
            }
        }
        
        idx = stk.top();
        
        for(int i=0;i<n;i++)
        {
            if(i != idx)
            {
                if(M[idx][i] ==1 || M[i][idx] ==0)
                {
                    return -1;
                }
            }
        }
        
        
        
        return idx;
    }
};