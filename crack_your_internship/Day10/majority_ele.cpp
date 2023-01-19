// https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    /*
    int majorityElement(vector<int>& nums) {

        unordered_map <int,int> mpp;

        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }   
        int n = nums.size();
        for(auto i: mpp)
        {
            if(i.second > n/2) return i.first;
        }

        return 0;
    }
    */  

    int majorityElement(vector <int> &nums)
    {
        int mostOccured=0,ct=0,n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(ct ==0) // initializes with the mostoccured 
                mostOccured = nums[i];
            // increment the counter
            if(nums[i]==mostOccured) ct++;
            else ct--; 
            // a point will come when our ct become 0 theat time we eill
            // look for other value and at the end return the value 
        }
        return mostOccured;
    }
};