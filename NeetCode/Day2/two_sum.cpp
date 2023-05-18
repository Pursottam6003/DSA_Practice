#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // result of size 2 
        vector <int> res(2,0); 

        unordered_map <int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            // find the element  
            int comp = target-nums[i];
            if(mpp.find(comp) != mpp.end()) 
            {
                res[0] = i;
                res[1] = mpp[comp];
            }

            else mpp[nums[i]] = i;
        }

        return res;
    }
};
int main()
{
    vector <int> nums = {1,2,5,6,9,4,11};

    class Solution sol;

    int k =7;

    vector <int> res = sol.twoSum(nums,k);

    for(int i=0;i<2;i++)
    {
        cout<<res[i] <<" ";
    }
    cout<<endl;

    return 0;
}