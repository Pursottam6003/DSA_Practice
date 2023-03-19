// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        // store all the elements in the array 

        for(int i:nums)
            mpp[i]++;
            
        int ans=0;

        for(auto x:mpp)
        {
            if(k==0)
            {    
                if(x.second>1)
                ans++;
            }
             else if(mpp.find(x.first+k)!=mpp.end())
                ans++;
        }
        
        return ans;
    }
};