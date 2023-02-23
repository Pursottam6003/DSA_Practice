class Solution {
public:

    bool isPossible(vector<int> &nums,int capacity,int k)
    {
        int temp=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(temp+ nums[i] > capacity)
            {
                cnt++;
                temp = nums[i];

                if(temp > capacity) return false;
            }
            else temp+= nums[i];
        }
        if(cnt < k) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int D) {

        int left = weights[0], right = 0;

        for (int w: weights)
        {
            left = min(left, w);
            right += w;
        }

        while(left <= right)
        {
            int mid = (left+right)/2;

            if(isPossible(weights,mid,D))
            {
                // then we can reduce it 
                right = mid-1;
            }
            else left = mid+1;
        }
        return left;
    }
};