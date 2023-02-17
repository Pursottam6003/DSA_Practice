// https://leetcode.com/problems/reverse-integer/description/
class Solution {
public:
    int reverse(int x) 
    {
        long long int res=0;
        while(x)
        {
            int t = x%10;
            res = ((res*10)+t);
            x = x/10;
        }   
        if(abs(res) >= pow(2,31)) return 0;
        return res; 
    }
};

