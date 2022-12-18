// https://leetcode.com/problems/find-the-duplicate-number/

/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Brute force
        // Either Use Set or Map for tracking the number which is present or not
        unordered_set <int> s;
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i]))
            {   // if already exits
                return nums[i];
                //return that duplicate number
            } // otherwise insert that number
            s.insert(nums[i]);
        }
        return 0;
    }
};

*/

class Solution {
public:
 
    int binary_serach(vector <int> &nums,int low,int high)
    {   
        int cnt;
        while(low <= high)
        {   cnt=0;
            int mid = (low+high)/2;
            // cnt number less than equal to mid
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i] <=mid) cnt++;
            }
            // if it is less then mid then update low 
            if(cnt <= mid)
                low = mid+1;
            else //else mid-1
                high = mid-1;
   
        }
        return low;
    }
    int findDuplicate(vector<int>& nums) {
        // Efficient Approach : Bunary Search
        int low = 1,high = nums.size()-1;
        return binary_serach(nums,low,high);
    }

};