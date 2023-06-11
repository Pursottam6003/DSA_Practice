
#include <bits/stdc++.h>
using namespace std;

// using hashmap 1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map <int,int> mpp;

        for(int i=0;i<nums.size();i++)
        {
            if(mpp.find(nums[i]) != mpp.end())
            {
                return true;
            }
            else mpp[nums[i]]++;
        }
        return false;
    }
};

// using set
class Solution2 
{
    public:

    bool containsDuplicate(vector <int> &nums)
    {
        unordered_set <int> s;
        for(int i=0;i<nums.size();i++) 
        {
            if(s.count(nums[i])) 
            {
                return true;
            }
            else s.insert(nums[i]);
        }
        return false;
    }
}

class Solution3 
{   
    // sort the above and find the element 
    public:
    bool containsDuplicate(vector <int> &nums)
    {

    }


}
int main()
{
    class Solution sol;

    vector <int> nums = {1,2,3,4,5,6,7,3};
    cout<<sol.containsDuplicate(nums)<<endl;
}