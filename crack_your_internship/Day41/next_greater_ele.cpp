// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long > stk;
        
        vector <long long > res (n,-1);
        
        for(int i=n-1;i>=0;i--)
        {
            
            while(!stk.empty() && stk.top() <= arr[i])
            {
                stk.pop();
            }
            
            if(!stk.empty())
            {
                res[i] = stk.top();
            }
            
            stk.push(arr[i]);
        }
        
        return res;
        
    }
};