#include <bits/stdc++.h>
using namespace std;


class Solution 
{
    public: 
    void printSubseq(int idx,int subSeqsum,int k,int n,int *arr,vector <int> &ds)
    {
        if(idx == n)
        {   
            if(subSeqsum == k)
            {
                // print within the function 
                for(int i=0;i<ds.size();i++)
                {
                    cout<<ds[i]<<" "; // print elements with " "
                }
                // at the end with a new line 
                cout<<endl;
            }
            return; 
        }

        // pick the element 
        ds.push_back(arr[idx]);
        // add into the sum 
        subSeqsum += arr[idx];
        // call the function of pick 
        printSubseq(idx+1,subSeqsum,k,n,arr,ds);

        // not pick the element 
        ds.pop_back();
        // remove the element's sum from subseqSum
        subSeqsum -= arr[idx];
        // call the function to not pick
        printSubseq(idx+1,subSeqsum,k,n,arr,ds);
    }
};


// driver function 
int main()
{   
    // given array (dummy)
    int arr[] = {17, 18, 6, 11, 2, 4};
    int n=6; // size of array 
    int subSeqsum = 0,k=6; // required subseq sum 

    // create an vector ds to store all the suubseq sum equal to k 
    vector <int> ds;
    // create an intence of variable
    class Solution sol;
    sol.printSubseq(0,subSeqsum,k,n,arr,ds);
    return 0;
}