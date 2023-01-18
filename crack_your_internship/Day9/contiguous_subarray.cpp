class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen=0,one=0,zero=0;
        int runningSum=0;
        // first of all replace the zero with -1

        for(int i=0;i<nums.size();i++) 
        {
            if(nums[i]==0) nums[i]=-1;
        }

        unordered_map <int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            runningSum+=nums[i];

            if(runningSum==0)
            {
                maxLen = max(maxLen,i+1);
            }
            // we need to store that eleement

            //but check is it present inside the map or not

            if(mpp.find(runningSum) != mpp.end())
            {
                // we need to update the len since this subrray is started from middle
                // not 0 
                maxLen = max(maxLen,i-mpp[runningSum]);
            }

            else 
            {
                // if not present 
                mpp[runningSum]=i;
            }
        }
        return maxLen;
        
    }
};