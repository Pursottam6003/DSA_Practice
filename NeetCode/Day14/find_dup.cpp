class Solution {
public:


/*
    int binary_serach(vector <int> &nums,int low,int high)
    {   
        
        
        int cnt;
        while(low <= high)
        {   cnt=0;
            int mid = (low+high)/2;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i] <=mid) cnt++;
            }

            if(cnt <= mid)
                low = mid+1;
            else 
                high = mid-1;
   
        }
        return low;
    }
*/
    int binary_serach(vector <int> &nums,int low,int high)
    {
        
        int cnt;
        while(low <= high)
        {   cnt=0;
            int mid = (low+high)/2;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i] <=mid) cnt++;
            }

            if(cnt <= mid)
                low = mid+1;
            else 
                high = mid-1;
   
        }
        return low;
    }
    int findDuplicate(vector<int>& nums) {
        
        return binary_serach(nums,0,nums.size()-1);
    }
};