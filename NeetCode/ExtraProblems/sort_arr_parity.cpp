// https://leetcode.com/problems/sort-array-by-parity-ii/description/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int i=0,j=1;
        int n = nums.size();

        while(i < n && j < n)
        {
            if(nums[i] %2 ==0)
            {
                i +=2; // move ahead 
            }

            else if(nums[j] %2 ==1)
            {
                /// go ahead 
                j +=2;
            }
            else 
            {
                swap(nums[i],nums[j]);
            }
        }
        return nums;
    }
};