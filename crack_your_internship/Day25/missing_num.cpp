// https://leetcode.com/problems/missing-number/description/
/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        vector <int> temp(nums.size()+1,-1);
        for(int i=0;i<nums.size();i++)
        {
            temp[nums[i]]++;
        }

        for(int i=0;i<temp.size();i++)
        {
            if(temp[i] ==-1)
                return i;
        }
        return 0;
    }
};
*/

class Solution 
{
    public:

    int missingNumber(vector<int> &nums)
    {
        int len = nums.size();
        int missing=len;
        for(int i=0;i<len;i++)
        {
            missing += i-nums[i];
        }
        return missing;
    }
};