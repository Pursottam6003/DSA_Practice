class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector <vector <int>> ans;
        vector <int> vec;
        // sort the number

        // edge cases 

        if(nums.size() <3) return {};

        
        sort(nums.begin(),nums.end());

        unordered_map <int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]] = i; // map the array eleemnets 
        }


        for(int i=0;i<nums.size()-2;i++)
        {   
            if(nums[i] >0) break;

            for(int j=i+1;j<nums.size()-1;j++)
            {
                int ele = -1 * (nums[i]+nums[j]);

                // find in the map 
                // check whether its exits or not then find its value 
                // and to avoid duplicacy we would avoid the codition 
                // like it shoudl be bigger then j 
                if(mpp.count(ele) && mpp.find(ele)->second > j)
                {
                    // the elemenet exists 
                    ans.push_back({nums[i],nums[j],ele});
                }
                // update j 
                j = mpp[nums[j]];
            }
            i = mpp[nums[i]];
        }


        return ans;
    }
};



// three sum 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector <vector <int>> res;

        // sort the vector 
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            int target = -nums[i];
            int front = i+1 ,back = nums.size()-1;

            while(front < back)
            {
                int sum = nums[front] + nums[back];

                if(sum < target)
                {
                    front++;
                }

                else if(sum > target)
                {
                    back--;
                }

                else 
                {
                    vector <int> triplet = {nums[i],nums[front],nums[back]};
                    res.push_back(triplet);

                    // skipping the duplicates for front
                    while(front < back && nums[front] == triplet[1]) front++;
                    // if any other duplicates exists  for back
                    while(front < back && nums[back] == triplet[2]) back--;
                }
            }

            // processing the duplicates of number i 
            while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }

        return res;
    }
};