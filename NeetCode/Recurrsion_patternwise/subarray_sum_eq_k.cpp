// https://leetcode.com/problems/subarray-sum-equals-k/description/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int total_sub=0;
        // create a map to store the elements 

        unordered_map <int,int> mpp;

        int sum=0;
        for(int i=0;i<nums.size();i++)
        {   
            sum +=nums[i];

            if(sum ==k)
            {
                // increment the total seq 
                total_sub++;
            }

            // find the element into map 
            if(mpp.find(sum-k) != mpp.end())
            {
                total_sub = mpp[sum-k]+total_sub;
            }
            // if sum exitsts 
            if(mpp.find(sum) != mpp.end()) mpp[sum]++;
            // otherwise addd them 
            else 
            {
                mpp[sum]=1;
            }
        }

        return total_sub;
    }
};