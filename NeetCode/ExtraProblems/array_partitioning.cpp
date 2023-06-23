class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // create three pointers
        int low=0,same=0,high=0;
        

        // interate over a loop and count the ocuurances
        for(auto i: nums)
        {
            if(i > pivot) high++;
            else if(i< pivot) low++;
            else same++;
        }

        int i=0,j=nums.size()-1;

        // update the pointer
        high = low +same;
        same = low;
        low = 0;

        vector <int> res(nums.size());
        for(auto n : nums)
        {
            if(n < pivot)
            {
                res[low++] = n;
            }

            else if(n == pivot)
            {
                res[same++] = n;
            }

            else 
            {
                res[high++] = n;
            }
        }

        return res;
    }
};