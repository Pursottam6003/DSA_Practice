// https://leetcode.com/problems/next-greater-element-ii/submissions/910609892/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack <int> stk;
        int n=nums.size();
        vector<int> res(n,-1);

        for(int i=2*n-1;i>=0;i--)
        {
            while(!stk.empty() &&  stk.top() <= nums[i%n])
            {
                // if bigger 
                stk.pop();
            }

            if(!stk.empty())
            {
                res[i%n] = stk.top();
            }

            else 
            {
                res[i%n] =-1;
            }
            stk.push(nums[i%n]);
        }

        return res;
    }
};