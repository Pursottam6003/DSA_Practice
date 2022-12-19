// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// Remove Duplicates from sorted array
/*
Approach 

Just check how many no are present 
the question itself says that it only cares about size of the unique elements 

*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // it is ovious that the number may contain unique elements
        int ct=1;
        // so counter =1
        for(int i=1;i<nums.size();i++)
        {   // since array is sorted so just check for the adjacent elements
            if(nums[i] ==nums[i-1])
            {
                continue; // if equal the continue
            }
            else nums[ct++]=nums[i]; // if not then increment the counter and add the values 
        }
        return ct;// return the counter
    }
};

/**
 * Similar approach but here they are tracking the duplicates elements
 * 
    int count = 0;
    for(int i = 1; i < n; i++){
        if(A[i] == A[i-1]) count++;
        else A[i-count] = A[i];
    }
    return n-count;
*/