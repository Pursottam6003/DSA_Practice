// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {

        int left=0,right=nums.size()-1;
        int res=INT_MAX;

        // int pos=0;
        while(left < right)
        {   

            if(nums[left] < nums[right]) return nums[left];
            int mid = (left + right)/2;

            if(nums[mid] >= nums[left])
            {
                left = mid+1;
            }

            else
            {
                right = mid;
            }            
        }   

        res = nums[left];
        return res;
    }
};