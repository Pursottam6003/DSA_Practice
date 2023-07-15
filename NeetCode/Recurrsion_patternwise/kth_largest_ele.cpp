// https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        //vector <int> subarr(n+1,0);

       
        // min heap
        priority_queue<int,vector<int> ,greater<int>> pq;

        for(int i=0;i<n;i++)
        {   
            int x = nums[i];
        
            if(pq.size()<k )
            {
                //push the element 
                pq.push(x);
            }

            else 
            {
                // echeck the top element 
                if(pq.top() <x)
                {
                    /// pop the top most element 
                    pq.pop();
                    pq.push(x);
                }
            }
        
        }

        //return the pq
        return pq.top();
    }
};