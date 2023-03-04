// https://leetcode.com/problems/insertion-sort-list/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // Efficient Approach : use the swap meethod

        int zero=0,two=nums.size()-1;
        // check the element which is zero or not 
        for(int i=0;i<=two;i++)
        {
           while(nums[i]==2 && i<two) swap(nums[i],nums[two--]);
           while(nums[i]==0 && i>zero) swap(nums[i],nums[zero++]);
        }
    }
};