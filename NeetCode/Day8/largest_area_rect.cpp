
// https://leetcode.com/problems/largest-rectangle-in-histogram/description/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0; // Base Condition
        int maxArea = 0;
        vector<int> left(n); //fill left boundary
        vector<int> right(n); // fill right boundary
        
        left[0] = -1;
        right[n - 1] = n;
        
        for(int i = 1; i < n; i++){
            int prev = i - 1; // previous for comparing the heights
            while(prev >= 0 && heights[prev] >= heights[i]){
                prev = left[prev]; // we have done this to minimise the jumps we make to the left
            }
            left[i] = prev;
        }
        // Similarly we do for right
        for(int i = n - 2; i >= 0; i--){
            int prev = i + 1; 
            while(prev < n && heights[prev] >= heights[i]){
                prev = right[prev]; 
            }
            right[i] = prev;
        }
        // once we have these two arrays fill we need width & area
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }
};

/*
class Solution 
{
    public:
    int largestRectangleArea(vector <int> heights)
    {
        int maxArea= 0,n = heights.size(),tp=0,curr=0;
        // initialize stack 
        stack <int> stk;

        for(int i=0;i<=n;i++)
        {
            curr = i==n ? 0 : heights[i];  // curr element
            // stack condition 

            while(!stk.empty() && heights[stk.top()] > curr )
            {
                tp = stk.top();
                stk.pop();

                int currHeight = heights[tp]* ((stk.empty()) ? i : i - stk.top()-1);

                maxArea = max(maxArea,currHeight);
            }
            stk.push(i);
        }
        return maxArea;
    }
};
*/

// approach 2 

class Solution 
{
    public:
    int largestRectangleArea(vector <int> &vec)
    {
        int res=0;
        // declare a stack 
        stack <int> stk;
        int n = vec.size();
        for(int i=0;i<=n;i++)
        {   
            // check hte currecnt height is bigger then the actual oone 
            // if its last element make it 0
            int currHeight = (i==n) ? 0 : vec[i]; 
            while(!stk.empty() && vec[stk.top()] > currHeight )
            {
                // to ge the top of the element 
                int tp = stk.top();
                // pop it 
                stk.pop();

                int area = vec[tp] * ((stk.empty()) ? i : i-stk.top()-1);
                res = max(res,area);
            }
            stk.push(i);
        }
        return res;
    }

};
