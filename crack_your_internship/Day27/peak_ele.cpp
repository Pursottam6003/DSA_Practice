
/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int pos=0,n=nums.size();

        if(nums.size()==2)
        {
            if(nums[0] > nums[1]) return 0;
            else return 1;
        }
        for(int i=1;i<n-1;i++)
        {
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1])
            {
                pos=i;
            }
        }

        //if(pos==0 && n >=3) pos = n;
        if(pos ==0 && n>1 )
        {
            if(nums[0] > nums[1]) return 0;
            else return n-1;
        }
        return pos;
    }
};
*/

class Solution {
public:
    /*
    int findPeakElement(vector<int>& nums) {
        
        int pos=0,n=nums.size();

        if(nums.size()==2)
        {
            if(nums[0] > nums[1]) return 0;
            else return 1;
        }
        for(int i=1;i<n-1;i++)
        {
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1])
            {
                pos=i;
            }
        }

        //if(pos==0 && n >=3) pos = n;
        if(pos ==0 && n>1 )
        {
            if(nums[0] > nums[1]) return 0;
            else return n-1;
        }
        return pos;
    } */
    int findPeakElement(vector <int> &nums)
    {
        int n = nums.size();
        if(n==1) return 0; // single element not possible to get peak element
        // check for 0th or n-1 th is the peakk element

        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        // search the peak in the remaining array
        int start =1,end=n-2; 

        while(start <= end)
        {   
            int mid = start + (end - start)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid] < nums[mid-1]) end = mid-1;
            else if(nums[mid] < nums[mid+1]) start = mid+1;
        }
        return -1;
    }
};