// https://leetcode.com/problems/maximum-product-of-three-numbers/submissions/899183554/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int mini1=INT_MAX,mini2 = INT_MAX;
        int max1 = INT_MIN,max2 = INT_MIN,max3 = INT_MIN;

        for(int n: nums)
        {   
            if(n <= mini1) 
            {
                mini2 = mini1;
                mini1 = n;
            }
            else if(n <= mini2)
            {
                mini2 = n;
            }


            if(n >= max1){
                max3 = max2;
                max2 = max1;
                max1 = n;
            }

            else if(n>= max2) {
                max3 = max2;
                max2 = n;
            }

            else if(n>= max3) 
            {
                max3 = n;
            }   
        }

        return max(max1*max2*max3,mini1*mini2*max1);
        //return max((mini1%INT_MAX*mini2%INT_MAX*max1%INT_MAX)%INT_MAX, (max1*max2*max3));
    }
};