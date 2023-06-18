
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0,high = nums.size()-1;
        while(low <= high)
        {   
            int mid = (low+high)/2; 

            if(nums[mid] == target) return mid;

            if(nums[low] <= nums[mid])
            {
               if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            else 
            {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
    

        }

        return -1;
    }
};
/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n =nums.size();
        if(n==0) return -1;

        int low=0,high=n-1;

        while(low < high)
        {
            int mid = (high+low)/2;
            // check the condition 
            // target and mid will be on same side
            // trying to say mid bada hona chahiye aur target bhi positive hona chahiye 
            if((nums[mid] - nums[n-1]) * (target - nums[n-1]) >0 )  
            {
                if(nums[mid] < target)
                {
                    low = mid+1;
                }

                else high = mid;
            }

            else if(target > nums[n-1])
            {
                high = mid; // target on the left side
            }

            else 
            {
                low = mid+1; // target on the right side 
            }
 
        }
        return  nums[low] ==target ? low : -1;
    }
};