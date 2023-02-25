// https://leetcode.com/problems/remove-element/description/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int ctVal=0;
        int fast=0,slow=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val)
            {
                fast++;
            }
            else 
            {
                nums[slow] = nums[fast];
                slow++;
                fast++;
                ctVal++;
            }
        }
    
      
        return ctVal;
    }
};