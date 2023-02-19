
// https://leetcode.com/problems/spiral-matrix/description/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        
//         int T,B,L,R,dir;
//         T=0;
//         B=A.size()-1;
//         L=0;
//         R=A[0].size()-1;
//         dir=0;
//         int i;
//         vector<int> ans;

//         while(T<=B && L<=R)
//         {
//             if(dir==0)
//             {
//                 for(i=L;i<=R;i++)
//                     ans.push_back(A[T][i]);
//                 T++;
//             }
//             else if(dir==1)
//             {
//                 for(i=T;i<=B;i++)
//                     ans.push_back(A[i][R]);
//                 R--;
//             }
//             else if(dir==2)
//             {
//                 for(i=R;i>=L;i--)
//                     ans.push_back(A[B][i]);
//                 B--;
//             }
//             else if(dir==3)
//             {
//                 for(i=B;i>=T;i--)
//                     ans.push_back(A[i][L]);
//                 L++;
//             }
//             dir=(dir+1)%4;
//         }
//         return ans;
    /*
        vector <int> res;
        
        int top=0,left=0,right = A[0].size()-1,bottom = A.size()-1;
        
        int dir=0;
        
        while(top <= bottom && left<= right)
        {   
            if(dir ==0)
            {
                for(int i=left;i<= right;i++)
                {
                    res.push_back(A[top][i]);
                }
                top++;
            }
            
            else if(dir ==1)
            {
                for(int i=top;i<=bottom;i++)
                {
                    res.push_back(A[i][right]);
                }
                right--;
            }

            
            else if(dir ==2)
            {
                for(int i=right;i>=left;i--)
                {
                    res.push_back(A[bottom][i]);
                }
                
                bottom--;
            }
            
            else if(dir ==3)
            {
                for(int i=bottom;i>=top;i--)
                {
                    res.push_back(A[i][left]);
                }
                left++;
            }
            
            dir = (dir+1)%4;
            
        }
        
        return res;
    */

    // since we need to return the array so lets do it 
    vector <int> res;

    // we need four variables to complte this task
    int n=A.size();
    int left =0,top=0,bottom=n-1,right=A[0].size()-1;

    int dir=0;
    while(left <= right && (top <=bottom))
    {
        if(dir ==0)
        {
            // do something
            for(int i=left;i<=right;i++)
            {
                res.push_back(A[top][i]);
            }
            top++;
        }

        else if(dir ==1)
        {
            // do 
            for(int i=top;i<=bottom;i++)
            {
                res.push_back(A[i][right]);
            }
            right--;
        }
        else if(dir ==2)
        {
            // do something
            for(int i=right;i>=left;i--)
            {
                res.push_back(A[bottom][i]);
            }
            bottom--;
        }

        else if(dir ==3)
        {
            // do 
            for(int i=bottom;i>=top;i--)
            {
                res.push_back(A[i][left]);
            }
            left++;
        }

        dir = (dir+1)%4;
    }

    return res;
    } 
};