class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low=1,high = 1e9;
        while(low <high)
        {
            int mid=(low+high)/2;

            int sum=0;
            for(int i: piles)
            {
                sum += (i+ mid-1)/mid;
            }

            /// checking the sum
            if(sum > h)
            {
                low = mid+1;
            }
            else 
            {
                high=mid;
            }
        }

        return low;

    }
};