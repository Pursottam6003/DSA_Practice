// https://leetcode.com/problems/3sum/description/
 
class Solution
{   
    public:
    vector <vector <int>> threeSum(vector <int> & nums)
    {
        // first sort the vector 
        sort(nums.begin(),nums.end());

        vector <vector <int>> res;

        // after that traverse the whole array
        for(int i=0;i<nums.size()-2;i++)
        {
            // we also have to make sure that there is no duplicates for ith eleement
            if(i==0 || (i>0 && nums[i] != nums[i-1]))
            {
                // then only proceeeds
                //int low = i+1,high = nums.size()-1,sum = 0 - nums[i];

                int low = i+1, hi = (int)(nums.size())-1, sum = 0 - nums[i];
                
                while (low < hi) {
                    if (nums[low] + nums[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(nums[i]); 
                        temp.push_back(nums[low]); 
                        temp.push_back(nums[hi]); 
                        res.push_back(temp);
                        
                        while (low < hi && nums[low] == nums[low+1]) low++;
                        while (low < hi && nums[hi] == nums[hi-1]) hi--;
                        
                        low++; hi--;
                    } 
                    else if (nums[low] + nums[hi] < sum) low++;
                    else hi--;
                }
            }

        }
        return res;
    }
};