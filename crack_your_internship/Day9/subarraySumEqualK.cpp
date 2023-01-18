// https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mpp;
        int res=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {   sum +=nums[i];

            if(sum == k)
            {
               res++;
            }

            // checking hte element is present of not inside our hashmap

            if(mpp.find(sum-k) != mpp.end())
            {
               // res = max(res,(i-mpp[sum-k]));
               res= (mpp[sum-k])+res;
            } 


            if(mpp.find(sum) != mpp.end()) mpp[sum]++;
            else mpp[sum]=1; //if it is not presenet
        }
        return res;

    }
};