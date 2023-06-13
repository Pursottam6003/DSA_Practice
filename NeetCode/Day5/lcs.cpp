class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map <int,bool> mpp;

        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]] = true;
        }

        for(int i =0;i < nums.size();i++)
        {   // if the element does not found
            if(mpp.count(nums[i]-1) >0)
            {
                mpp[nums[i]] = false; 
            }
        }


        int maxlen =0;

        for(int i=0;i<nums.size();i++)
        {
            if(mpp[nums[i]] == true)
            {
                int j = 0;
                int count =0;
                while(mpp.count(nums[i]+j) >0)
                {
                    j++;
                    count++;
                }

                if(count > maxlen){
                    maxlen = count;
                }
            }
        }
        return maxlen;
    }
};

// set approach 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set <int> s;

        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int res=0;
        for(auto x : s)
        {
            // int x =  nums[i];

            if(s.count(x-1) ==0)
            {
                int y = x+1;

                while(s.count(y))
                {
                    y++;
                }

                res = max(res,y-x);
            }
        }
        return res;

    }
};