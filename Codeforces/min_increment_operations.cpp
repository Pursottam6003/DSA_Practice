class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 0) return 0;
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int i = 0;
        while(i < len){
            int j = i + 1;
            while(j < len && nums[j] == nums[i]) j++;
            int diff = nums[j - 1] - nums[i];
            int count = j - i;
            if(i == 0){
                ans += count * (count - 1) / 2;
                ans += count * diff;
            }
            else{
                int prev_diff = nums[i] - nums[i - 1];
                ans += count * (count - 1) / 2;
                ans += count * (diff - prev_diff);
            }
            i = j;
        }
        return ans;
        
        
    }


};