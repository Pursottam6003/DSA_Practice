#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    // method 2
    int subarraysDivK(vector <int> &arr,int k)
    {
        vector <int> count(k); // initialize with the size

        count[0]=1;
        int subarry_ct=0,rem=0,sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            sum = (sum %k)%k;
            // if negative sum value we need to add k
            if(sum <0) sum +=k;
            // calculating the rem 
            rem  = sum;
            subarry_ct += count[rem];
            // update the count 
            count[rem]++;
        } 
        return subarry_ct;
    }
};

// method 3

int subarraysDivByK(vector <int> &arr,int k)
{
        // taking the unordered map to store the frequency of elements
        unordered_map <int,int> mpp;

        int subarr=0,sum=0;
        mpp[0]=1;
        for(int i=0;i<arr.size();i++)
        {
            sum += arr[i];

            int rem = ((sum%k) + k)%k;

            if(mpp.find(rem) != mpp.end())
            {
                subarr+= mpp.find(rem)->second;
                mpp[rem]++;
            }
            else mpp[rem]++;
        }
        return subarr;
}

int main(){}
