#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void productExceptSelf(vector<int>& nums) {
        // brute force 

        vector <int> res(nums.size(),0);
        res[0] =1;
        for(int i=1;i<nums.size();i++)
        {
            res[i] = res[i-1]*nums[i-1];
        }

        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
        
        int prod=1;

        for(int i=nums.size()-1;i>=0;i--)
        {
            res[i] = res[i] *prod;
            prod *= nums[i];
        }
        return;
    }
};

int main()
{
    class Solution sl;
    vector <int> vec ={1,2,3,4};

    sl.productExceptSelf(vec);
}