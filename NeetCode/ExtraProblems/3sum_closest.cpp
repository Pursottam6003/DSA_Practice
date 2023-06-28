class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        // if the size is less then 3 

        if(nums.size()<3) return 0;
        // initialized the closest
        int closest = nums[0]+nums[1]+nums[2];

        // sort them 
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;i++)
        {   
            if(i>0 && nums[i] == nums[i-1]) continue;
            int first=i,second =i+1,third=nums.size()-1;

            while(second < third)
            {
                int curSum = nums[first]+nums[second]+nums[third];

                if(curSum == target) return curSum;

                if(abs(target-curSum) < abs(target-closest))
                {
                    // update cloasest
                    closest = curSum;
                }

                if(curSum > target)
                {
                    third--;
                }
                else 
                {
                    second++;
                }
            }
        }

        return closest;

    }
};