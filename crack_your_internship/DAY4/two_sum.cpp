class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map <int,int> mpp;
        vector <int> res;
        int comp=0;
        for(int i=0;i<nums.size();i++){
            comp = target-nums[i];

            if(mpp.find(comp) !=mpp.end())
            {
                res.push_back(mpp.find(comp)->second);
                res.push_back(i);
            }
            else 
            {
                mpp[nums[i]]=i;
            }
        }
        return res;
        
    }
};