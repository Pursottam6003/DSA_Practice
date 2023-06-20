// 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque <int> dq;
        int n = nums.size();

        vector <int> res;
        for(int i=0;i<n;i++)
        {
            // when we need to remove the leftmost window element
            if(!dq.empty() && dq.front() == i-k) 
                dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                // pop that redundent elements 
                dq.pop_back();
            }

            dq.push_back(i);
            // if it is inside the window
            // for pushing the most updated element into the vector
            if(i >= k-1 ) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};