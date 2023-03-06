// https://leetcode.com/problems/next-greater-element-i/submissions/910075452/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> stk;
        unordered_map <int,int> mpp;
        vector <int> res (nums1.size(),-1);


        int n = nums2.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() && stk.top() <= nums2[i])
            {
                stk.pop();
            }

            if(stk.empty())
            {
                mpp[nums2[i]]=-1;
            }
            else 
            {
                mpp[nums2[i]]=stk.top();
            }
            stk.push(nums2[i]);
        }

        int idx=0;
        for(int i=0;i<nums1.size();i++)
        {   // finding that nums1 into map
            res[i] = mpp[nums1[i]];
        }

        return res;
    }
};