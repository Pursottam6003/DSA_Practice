/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // Brute Force : count the zero one two 
        int zero=0,one=0,two=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) zero++;
            else if(nums[i]==1) one++;
        }

        two = nums.size()-(zero+one);
        int ct=0;
        // then arrange them accordingly
        while(zero--) nums[ct++]=0;
        while(one--) nums[ct++]=1;
        while(two--) nums[ct++]=2;
    }
};

*/

/*
I had a hard time grasping this one so I thought I'd write it down, maybe it will help you too.

Iterate over the array, maintaining two pointers, one at the "low" index, 0, and one at the "high", nums.length - 1.

Everything to the left of low in the array and everything to the right of high in the array will be assumed sorted. As we iterate through the array, we update our pointers, taking account for two cases

If the index in the array is equal to 0, we swap that with our current low index and then increment the low index, since we know that everything to the left of that index is properly sorted.

Else if the index in the array is equal to 2, we swap that with our current high index and decrement the high index, since everything to right of the high index is sorted. Also take care in this case to decrement i since we will want to reconsider the inserted element.

We've accounted for if the indexes are 0 or 2, the only other option is if the index is a 1, in which case we will just leave it in place.

Our loop ends when we meet the high index, since we know everything to the right of high is properly sorted
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // Efficient Approach : use the swap meethod

        int zero=0,two=nums.size()-1;
      
       for(int i=0;i<=two;i++)
       {
           while(nums[i]==0 && i>zero) swap(nums[i],nums[zero++]);
           while(nums[i]==2 && i<two) swap(nums[i],nums[two--]);
       }
    }
};