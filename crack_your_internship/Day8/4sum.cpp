/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        vector <vector <int>> res;
        for(int i=0;i<nums.size()-1;i++)
        {   
            if(i==0 || (i>0 && nums[i] !=nums[i-1]))
            {
                for(int j=i+1;j<nums.size()-2;j++)
                {   int sec = j;
                    if(j==1 || (j>1 && nums[j] != nums[j-1]))
                    {
                        int low=i+2,high = nums.size()-1;
                        while(low < high)
                        {   
                            int sum = (nums[i]+nums[sec]+nums[low]+nums[high]);
                            if(sum == target)
                            {
                                vector <int> temp;
                                // temp.push_back({nums[i],nums[sec],nums[low],nums[high]});
                                temp.push_back(nums[i]);
                                temp.push_back(nums[sec]);
                                temp.push_back(nums[low]);
                                temp.push_back(nums[high]);
                                low++;
                                high--;

                                // to avoid duplicates
                                while(low <high && nums[low] != nums[low+1]) low++;
                                while(low <high && nums[high] != nums[high-1]) high--;
            
                                res.push_back(temp);
                            }

                            else if(sum >target) high--;
                            else low++;
                        }
                    }
                }
            }
        }

        return res;

        
    }
};
*/

typedef  long long int lli;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector <vector <int>> res;

        if(nums.empty())
            return res;
        
        lli n = nums.size();
        //sort the array

        sort(nums.begin(),nums.end());

        for(lli i=0;i<n;i++)
        {
            lli target_3 = target - nums[i];

            for(lli j=i+1;j<n;j++)
            {
                lli target_2 = (target_3-nums[j]);

                lli front =j+1;
                lli back = n-1;

                while(front < back)
                {
                    lli two_sum = nums[front] + nums[back];

                    if(two_sum > target_2)
                    {
                        back--;
                    }
                    else if(two_sum <target_2) front++;

                    else 
                    {
                        //that means it is equal 
                        vector <int> quad(4,0);

                        quad[0] = nums[i],quad[1] = nums[j],quad[2] =nums[front],quad[3] = nums[back];

                        res.push_back(quad);

                        // to avoid duplicates 
                        while(front < back && nums[front] == quad[2]) front++;
                        while(front <back && nums[back] == quad[3]) back--;
                    }
                }
                // processing the duplicates of number 2
                while(j+1 < n && nums[j] == nums[j+1]) ++j;
            }
            while(i+1 <n && nums[i] == nums[i+1])++i;
        }
        return res;
    }
};