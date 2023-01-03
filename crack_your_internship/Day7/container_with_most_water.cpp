// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& arr) {
        int maxi_container=0;
        int n = arr.size();

        int left=0,right=n-1,temp,h=0;
        while(left <right)
        {
            h = min(arr[left],arr[right]) ;
            
            if(h ==arr[left])
            {
                left++;
            }
            else 
            {
                right--;
            }
            temp = h* ((right-left)+1);

            maxi_container = max(maxi_container,temp);
        }

        return maxi_container;
    }
};