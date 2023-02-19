// https://practice.geeksforgeeks.org/problems/permutations-in-array1747/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        // accending sorting
        sort(a,a+n);
        
        // decending sorting 
        sort(b,b+n,greater<int>());
        
        for(int i=0;i<n;i++)
        {
            if(a[i]+b[i] < k) return false;
        }
        return true;
    }
};

/**
 * Method 2:
In the above case, we were just sorting the elements and checking the statement for n time (making pairs of ith index) resulting in time complexity of O(n log n).

As we can see we only need to check that is there any pair whose sum is greater than K. To solve it we have to just find the maximum pair sum. 
*/
#include<bits/stdc++.h>
using namespace std;

bool isPossible(long long arr1[] , long long arr2[] , int n , long long K){
	//FINDING THE MAX ELEMENT

	long long a = *max_element(arr1 , arr1+n); // *max_element is STL function used to find the max element from the array.
	long long b = *max_element(arr2 , arr2+n);

	long long ans = a+b;

	// CHECKING THE CONDITION
	return ans >= K;
}

int main(){
	long long arr1[] = {2,1,3};
	long long arr2[] = {7,8,9};

	long long k = 5;

	int n = sizeof(arr1)/sizeof(arr1[0]);

	if (isPossible(arr1 , arr2 , n , k))
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
}

// This code is contributed by Divyansh Garg (dishugarg1511)
