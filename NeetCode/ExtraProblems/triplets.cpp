/**
Hashing Technique.
O(N) space and O(N) Time :

1.Simply first store all the elements of array in a map or a set.
2.Now again traverse the array and see for every element say 'x', if there are two more elements present in map i.e x+diff and x-diff.3
3.If present then increment the count by 1.
4.Return the count variable.
*/

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
        int res=0;
        // create a hashmap 
        unordered_map <int,int> mpp;

        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            if(mpp[nums[i]+diff] && mpp[nums[i]-diff])
            {
                res++;
            }
        }
        return res;
    }
};