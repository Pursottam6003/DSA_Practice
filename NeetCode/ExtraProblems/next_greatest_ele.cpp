// https://leetcode.com/problems/next-greater-element-i/solutions/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();


        // creating a unordered map to store the values of num2;
        unordered_map <int,int> mpp;
        vector <int> res(nums1.size(),0);
        // create a stack 
        stack <int> stk;

        for(int i=n2-1;i>=0;i--)
        {
            while(!stk.empty() && stk.top() <= nums2[i])
            {
                // if then pop until it top is greater then num
                stk.pop();
            }
            // if the stack becomes empty even it does not able to find any 
            // bigger element
            if(stk.empty())
            {
                // store -1 into map for value 
                mpp[nums2[i]] =  -1;
            }

            else 
            {
                mpp[nums2[i]] = stk.top();
            }

            stk.push(nums2[i]);
        }

        // now updat into the resultent array 

        for(int i=0;i<nums1.size();i++)
        {
            res[i] = mpp[nums1[i]]; // its second value ie key value 
            // automatically will be added 
        }
         
        return res;
    }
};