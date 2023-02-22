//https://practice.geeksforgeeks.org/problems/aggressive-cows/1
class Solution {
public:
    
    bool possible(int mid, vector<int> &stalls,int k)
    {
        int i,j,temp = stalls[0],count =1;
        
        for(i=1;i<stalls.size();i++)
        {
            if(stalls[i] - temp >= mid)
            {
                temp = stalls[i];
                count++;
            }
            if(count ==k)
                return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
 
        sort(stalls.begin(),stalls.end());
        // to get the order of placement of cows
        
        // settling the boundry for binary search 
        int max_diff=stalls[n-1] -stalls[0]; // last and first
        int ans=1; // minimum spacing would be 1 
        int min_diff=1,mid;
         while(min_diff <= max_diff)
        {
            // cout<<diff_min<<diff_max<<" ";
            mid=(min_diff + max_diff)/2;
            //   cout<< mid<<" ";
            if(possible(mid,stalls,k))
            {
                // cout<< mid<<" ";
                min_diff=mid+1;
                ans=max(ans,mid);
            }
            else
            {
                max_diff =mid-1;
                
            }
            
        }
        return ans;
    }
};