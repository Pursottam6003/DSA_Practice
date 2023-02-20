//https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        long long int l=nums[0],r=nums[n-1]; // left right
        vector<long long int> vec(n,1);
        
        for(int i=1;i<n;i++)
        {
            vec[i] *=l;
            l *= nums[i];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            vec[i]*=r;
            r *= nums[i];
        }
        return vec;
    }
};