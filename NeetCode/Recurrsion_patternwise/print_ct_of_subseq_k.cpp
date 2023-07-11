#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem
class Solution 
{
    public: 
    int  countSubseq(int idx,int subSeqsum,int k,int n,int *arr)
    {
        if(idx == n)
        {   
            if(subSeqsum == k)
            {
                return 1;
            }
            return 0; 
        }
 
        // add into the sum 
        subSeqsum += arr[idx];
        // call the function of pick 
        int left = countSubseq(idx+1,subSeqsum,k,n,arr);
 
        // remove the element's sum from subseqSum
        subSeqsum -= arr[idx];
        // call the function to not pick
        int right = countSubseq(idx+1,subSeqsum,k,n,arr);

        return left+right;
    }
};


// driver function 
int main()
{   
    // given array (dummy)
    int arr[] = {17, 18, 6, 11, 2, 4};
    int n=6; // size of array 
    int subSeqsum = 0,k=6; // required subseq sum 
 
    // create an intence of variable
    class Solution sol;
    cout<<sol.countSubseq(0,subSeqsum,k,n,arr)<<endl;
    return 0;
}