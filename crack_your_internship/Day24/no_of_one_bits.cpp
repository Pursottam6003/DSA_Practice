// https://leetcode.com/problems/number-of-1-bits/description/
/*
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;

        if(n==0) return 0;
        if(n&1)
        {
            res=1+hammingWeight(n>>1); //right shifting
        }
        else 
        {
            res =0+hammingWeight(n>>1);
        }

        return res;
    }
};

*/

class Solution 
{
    public:
    int hammingWeight(uint32_t n)
    {
        long long ans=0;
        while(n)
        {   if(n&1)
                ans++;
            n = n>>1;//right shift
        }
        return ans;
    }
};