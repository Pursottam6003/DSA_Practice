class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        

        int res=0;
        int low = 1,high = 1e9;

        while(low <high)
        {
            int mid = (low+high)/2;

            int hours=0;
            for(int i=0;i<piles.size();i++)
            {
                hours += (piles[i]+mid-1)/mid;
            }

            if(hours <=h)
            {
                high = mid;
            }
            else 
            {
                low = mid+1;
            }
        }
        return low;
    }
};