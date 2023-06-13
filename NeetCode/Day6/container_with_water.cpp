/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxiArea = INT_MIN;
        int currArea = 0;
        int front = 0, back = height.size()-1;
        
        while(front < back)
        {
            int h = min(height[front],height[back]);

            if(h == height[front])
            {
                front++;
            }

            else 
            {
                back--;
            }

            currArea = h * ((back-front)+1);
            maxiArea  = max(maxiArea,currArea);
        }
        return maxiArea;
    }
};

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int area = 0;
        int lptr = 0 ;
        int rptr = height.size()-1;
        // cout<<lptr<<" "<<rptr<<"\n";
        while(lptr < rptr){
            int prod = min(height[lptr],height[rptr]) * (rptr-lptr);
            area = max(prod,area);
            if(height[lptr] < height[rptr]){
                lptr++;
            }else{
                rptr--;
            }
        }
        return area;
    }
};