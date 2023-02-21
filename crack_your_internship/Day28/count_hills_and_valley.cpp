// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int hills=0,valley=0,n=nums.size();
        
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i-1]) continue;
            int j=i-1,k=i+1; // left most and right most

            while(k<n && nums[i] == nums[k]) k++;
            if(k>=n) continue;

            if(nums[i] > nums[j] && nums[i] > nums[k]) hills++;
            else if(nums[i] < nums[j] && nums[i] < nums[k]) valley++;
        }
        int res =hills+valley;
        return res;
    }
};