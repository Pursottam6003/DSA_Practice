
/* //Approach 1
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
 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        
        for(int i = 0; i <= n; i++){
            int currHeight = i == n ? 0 : heights[i];
            // check if currHeight becomes greater then height[top] element of stack. we do a push because it's an increasing sequence
            // otherwise we do pop and find area, so for that we write a while loop
            while(!st.empty() && currHeight < heights[st.top()]){
                int top = st.top(); st.pop(); // current element on which we are working
                // now we need width & area
                int width = st.empty() ? i : i - st.top() - 1; // width differ if we stack is empty or not empty after we pop the element
                int area = heights[top] * width; // current height * width
                maxArea = max(area, maxArea);
            }
            // if it doesn't enter in while loop, it means it's an increasing sequence & we need to push index
            st.push(i);
        }
        return maxArea;
    }
};
*/

/*
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

*/


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









