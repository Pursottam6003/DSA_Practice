class Solution {
public:

    int binary_search(int ind,vector <vector<int>> &events,int value)
    {
        int lo = ind;
        int hi = events.size()-1;

        int req= -1;

        while(lo <= hi)
        {
            int mid = (lo+hi)/2;
            if(events[mid][0] > value)
            {
                req = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return req;
    }
    int helper(int idx,vector <vector<int>> &events,int k,vector <vector<int>> &dp)
    {
        if(idx >= events.size() || k==0 || idx ==-1) return 0;

        if(dp[idx][k] != -1) return dp[idx][k];

        int reqInd = binary_search(idx+1,events,events[idx][1]);

        int c1 = events[idx][2] + helper(reqInd,events,k-1,dp);
        int c2 = helper(idx+1,events,k,dp);

        return dp[idx][k] = max(c1,c2);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        
        // sort the events 
        sort(events.begin(),events.end());
        int n = events.size();

        vector <vector<int>> dp(n+5,vector<int>(k+1,-1));
        return helper(0,events,k,dp);
    }
};