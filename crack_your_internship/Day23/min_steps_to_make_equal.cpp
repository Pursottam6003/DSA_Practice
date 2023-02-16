// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        if(nums.size()==0) return 0;

        int mini = nums[0];
        for(int i=0;i<nums.size();i++)
        {
            mini = min(nums[i],mini);
        }
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            res += abs(nums[i]-mini);
        }
        
        return res;
    }
};