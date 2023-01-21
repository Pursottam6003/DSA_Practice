
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& pts, int k) {
        priority_queue<pair<int, int>> pq; // max-heap
        pq.push({pts[0][1]-pts[0][0],pts[0][0]});
        int ans= INT_MIN;
        for(int i=1;i<pts.size();i++) {
            int sum = pts[i][0]+pts[i][1];
            while(!pq.empty() && pts[i][0]-pq.top().second>k) pq.pop();
            if(!pq.empty())ans = max(ans,sum+pq.top().first);
            pq.push({pts[i][1]-pts[i][0],pts[i][0]});
            cout<<i<<' '<<ans<<'\n';
        }
        cout<<'\n';
        return ans;
    }
};