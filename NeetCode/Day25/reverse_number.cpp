// nice approach
class Solution
{
public:
    /*
    Need to filter out 214748368, 214748369 for INT_MAX case. (similarly -1214748369 for INT_MIN) if we look just rev > INT_MAX/10, then it cant' filter out the numbers.
    **/
    int reverse(int x)
    {
        int rev = 0;
        while (x != 0)
        {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

// another approach

class Solution
{
public:
    int reverse(int x)
    {
        long long int res = 0;
        while (x)
        {
            int t = x % 10;
            res = ((res * 10) + t);
            x = x / 10;
        }
        if (abs(res) >= pow(2, 31))
            return 0;
        return res;
    }
};