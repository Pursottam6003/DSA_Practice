// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int lst_pos =0;
        // make one variable as lst_pos
        // check the num is natural no or not
        for(int i=0;i<nums.size();i++)
        {   
            // if not zero then swap with the value and incrment the counter last_pos

            // Dry run 
            /*
                i=0
                [0,1,0,3,12]
                lst_pos=0

                since num[i]==0 so do nothing

                i =1
                [0,1,0,3,12]
                lst_pos =0

                since nums[i]!=0 
                swap(nums[i],nums[lst_pos++])
                
                i=2
                [1,0,0,3,12]
                lst_pos=1

                since do nothing nums[i]==0

                i=3
                swap(nums[i],nums[lst_pos++])
                1 3 0 0 12
                lst_pos=2

                i=4 
                nums[i]!=0
                swap(nums[i],nums[lst_pos++])

                final 
                1 3 12 0 0  
            */
            if(nums[i] !=0)
            {
                swap(nums[i],nums[lst_pos++]);
            }
        }
    }
};