// https://leetcode.com/problems/single-number/description/
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {

        int single = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            single = single ^ nums[i];
        }
        return single;
    }
};