//  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/902978021/
class Solution {
public:

    int findMin(vector<int>& nums) {
        int n  = nums.size();
        int l=0,r= n-1;

        //int mini=INT_MAX;
        while(l <r)
        {
            if(nums[l] < nums[r]) return nums[l];
            int mid = (l+r)/2;

            if (nums[mid] >= nums[l]) {
                l = mid+1;
            } 
            else {
                r = mid;
            }
        }
        return nums[l];
    }
};