// https://leetcode.com/problems/missing-number/description/
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {

        int n = nums.size();
        int sum = (n * (n + 1)) / 2;

        int numberSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            numberSum += nums[i];
        }

        return sum - numberSum;
    }
};