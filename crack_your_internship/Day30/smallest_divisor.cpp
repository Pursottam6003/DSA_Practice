// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
class Solution {
public:

    int smallestDivisor(vector<int>& nums, int k) {
        int n = nums.size();

        int low=1,high = 1e7;

        while(low <high)
        {
            int mid = (low+high)/2;
            int sum=0;
            
            for(int i=0;i<n;i++)
            {
                sum += (nums[i]+mid -1)/mid;
            }


            if(sum > k)
            {
                low=mid+1;
            }
            else 
            {
                high = mid;
            }
        }
        
        return low;
    }
};