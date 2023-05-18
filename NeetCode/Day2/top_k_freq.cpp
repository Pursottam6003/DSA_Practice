// https://leetcode.com/problems/top-k-frequent-elements/description/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map <int,int> mpp;
        vector <int> res;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }

        priority_queue <pair<int,int>> pq;

        for(auto it: mpp)
        {
            pq.push(make_pair(it.second,it.first));
        }    

        while(!pq.empty() && k--)
        {
            pair<int,int> p = pq.top();
            res.push_back(p.second);
            pq.pop();
        }
    
        return res;
    }
};