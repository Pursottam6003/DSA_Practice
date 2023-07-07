// recursive 

// https://leetcode.com/problems/powx-n/description/
class Solution {
public:
    double binaryExp(double x, long long n) {
        // Base case, to stop recursive calls.
        if (n == 0) {
            return 1;
        }
       
        // Handle case where, n < 0.
        if (n < 0) {
            return 1.0 / binaryExp(x, -1 * n);
        }
       
        // Perform Binary Exponentiation.
        // If 'n' is odd we perform Binary Exponentiation on 'n - 1' and multiply result with 'x'.
        if (n % 2 == 1) {
            return x * binaryExp(x * x, (n - 1) / 2);
        }
        // Otherwise we calculate result by performing Binary Exponentiation on 'n'.
        else {
            return binaryExp(x * x, n / 2);
        }
    }

    double myPow(double x, int n) {
        return binaryExp(x, (long long) n);
    }
};

// iterative 
class Solution {
public:
    double myPow(double x, int n) {
        
        long long  nn = n;

        double res=1.0;

        if(nn <0) nn = abs(nn);

        while(nn)
        {
            if(nn==0) break;

            if(nn %2==0)
            {
                x = x*x;
                nn = nn/2;
            }

            else 
            {
                res = res * x;
                nn = nn-1;
            }
        }

        if (n < 0) res = (double)(1.0) / (double)(res);


        return res;
    }
};

#define mod 1000004;
class Solution {
public:
    double res=1.0;
    void recursion(double x, long long n)
    {
        if(n==0) return;
        if(n%2==0)
        {
            x = (x*x);
            n = n/2;
        }

        else 
        {
            res = (res*x);
            n = n-1;
        }
        recursion(x,n);
    }
    double myPow(double x, int n) {
        double negSign=1.0;

        // if(x==0) return 0.0;
       if(x<0 && n%2==0)
       {
           x= abs(x);
       }

       else if(x<0 && n%2==0)
       {
           x = abs(x);
           negSign = -1.0;
       }
       if(n<0)
       {  
           n = abs(n);
           x = 1/x;
       }

       recursion(x,(long long)n);
       return res*negSign;
        
    }
};

 