// https://leetcode.com/problems/split-array-largest-sum/
class Solution {
public:

    bool isPossible(vector<int> &nums,int capacity,int k)
    {
        int temp=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(temp+ nums[i] > capacity)
            {
                cnt++;
                temp = nums[i];

                if(temp > capacity) return false;
            }
            else temp+= nums[i];
        }
        if(cnt < k) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        
        // we will apply binary search but for that 
        // lets find the boundary 

        int n = nums.size();

        if(k > n) return -1;

        int low=nums[0],high =0;

        for(int i=0;i<nums.size();i++)
        {
            low = min(nums[i],low);
            high += nums[i]; // sum of every element
        }

        // since we get low and high 

        while(low<=high)
        {
            int mid = (low+high)/2;

            if(isPossible(nums,mid,k))
            {
                high = mid-1;
            }
            else 
            {
                low = mid+1;
            }
        }

        return low;

    }
};