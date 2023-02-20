//https://leetcode.com/problems/search-insert-position/description/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // checking some base casees
        int n =nums.size();

        // applying binary search in  1 - n-1 element
        int start=0,end=n-1;

        while(start <end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) start = mid+1;
            else if(nums[mid] > target) end = mid-1;
        }

        if(nums[start] < target ) return start+1;
        //else return start;
        return start;
  
       
    }
};