class Solution {
public:

    int recursive_binary(vector <int> &nums,int low,int high,int target)
    {
        // base case 

        if(low <= high) return;

        int mid = (low+high)/2;

        if(nums[mid] == target) return mid;
        if(nums[mid] > target) 
            return recursive_binary(nums,low,mid-1,target);
        
        return recursive_binary(nums,mid+1,high,target);

    }
    int search(vector<int>& nums, int target) {

        int low = 0,high= nums.size()-1;

        int mid;
        while(low <= high)
        {
            mid = (low + high)/2;

            if(nums[mid] == target) return mid;

            else if(nums[mid] > target) high = mid-1;

            else low = mid+1;
        }   

        return -1;
    }
};

  int recursive_binary(vector <int> &nums,int low,int high,int target)
    {
        // base case 
        int mid = (low+high)/2;

        if(high >= low)
        {
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) 
                return recursive_binary(nums,low,mid-1,target);
            
            else if(nums[mid] <target)
                return recursive_binary(nums,mid+1,high,target);

        }

        return -1;
    }