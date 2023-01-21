// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution 
{
    public:
    int largestRectangleArea(vector <int> heights)
    {
        int n = heights.size();

        // we are travesring from tje left to get the most longest elee
        // inserting the most longest into stack
        stack <int> stk;
        // traverse 
        int maxArea=0;
        for(int i=0;i<=n;i++)
        {
            int currHeight = i==n ? 0 : heights[i];

            // compare with stack top 

            while(!stk.empty() && heights[stk.top()] > currHeight)
            {
                int top = stk.top();
                stk.pop(); // remvoing tthe top eleleent and 
                // calculating the curr area 

                int width = stk.empty() ? i : i-stk.top()-1;
                int area = heights[top]*width;

                maxArea = max(area,maxArea);
            }
            stk.push(i); // insert the index 
        }
        return maxArea;
    }
};