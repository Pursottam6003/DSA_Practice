// https://www.geeksforgeeks.org/check-reversing-sub-array-make-array-sorted/
// C++ program to check whether reversing a sub array
// make the array sorted or not

/*
Input : arr [] = {1, 2, 5, 4, 3}
Output : Yes
By reversing the subarray {5, 4, 3}, the array will be sorted.

Input : arr [] = { 1, 2, 4, 5, 3 }
Output : No



Method 3: Linear time solution (O(n)):

The idea to solve this problem is based on the observation that if we perform one rotation of any subarray in the sorted array (increasing order), then we there will be exactly one subarray which will be in decreasing order. So, we have to find that rotated subarray and perform one rotation on it. Finally check if the array becomes sorted or not.


Initialize two variables x and y with -1.
Iterate over the array.
Find the first number for which a[i] > a[i+1] and store it into x. 
Similarly, Store index i+1 as well into y, As this will keep track of the ending of the subarray which is needed to reverse.
Check if x == -1 then array is already sorted so return true.
Otherwise, reverse the array from index x to index y.
Traverse the array to check for every element is sorted or not.
If not sorted, return false.
Finally, return true.


*/
#include<bits/stdc++.h>
using namespace std;

// Return true, if reversing the subarray will sort t
// he array, else return false.
bool checkReverse(int arr[], int n)
{
	int x =-1,y=-1;

	// first find the point when the array is decreasing 
	for(int i=0;i<n-1;i++)
	{	// check if previous element is bigger then above 
		if(arr[i+1] > arr[i]) 
		{	
			if( x==-1)
			{
				// first time
				x=i;
				// then we dont need to update though 
			}
			y = i+1; // upto which element it is updating 
		}

	 
	}
	// reverse the array
	if(x != -1)
	{
		reverse(arr+x,arr+y+1);

		// now ehck wheather element is sorted or not
		for(int i=0;i<n-1;i++)
		{
			if(arr[i] > arr[i+1]) return false; 
		}
	}

	return true;

} 

// Driver Program
int main()
{
	int arr[] = {1, 3, 4, 10, 9, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	checkReverse(arr, n)? cout << "Yes" : cout << "No";
	return 0;
}


/*
Method 4: Another linear time solution (O(n)):
Observe, that the answer will be True when the array is already sorted or when the array consists of three parts. The first part is increasing subarray, then decreasing subarray, and then again increasing subarray. So, we need to check that array contains increasing elements then some decreasing elements, and then increasing elements if this is the case the answer will be True. In all other cases, the answer will be False.

Note: Simply finding the three parts does not guarantee the answer to be True eg consider


arr [] = {10,20,30,40,4,3,2,50,60,70} 
The answer would be False in this case although we are able to find three parts. We will be handling the validity of the three parts in the code below.

Below is the implementation of this approach: 

*/

// C++ program to check whether reversing a sub array
// make the array sorted or not
#include<bits/stdc++.h>
using namespace std;
 
// Return true, if reversing the subarray will sort t
// he array, else return false.
bool checkReverse(int arr[], int n)
{
    if (n == 1)
        return true;
 
    // Find first increasing part
    int i;
    for (i=1; i < n && arr[i-1] < arr[i]; i++);
    if (i == n)
        return true;
 
    // Find reversed part
    int j = i;
    while (j < n && arr[j] < arr[j-1])
    {
        if (i > 1 && arr[j] < arr[i-2])
            return false;
        j++;
    }
 
    if (j == n)
        return true;
 
    // Find last increasing part
    int k = j;
 
    // To handle cases like {1,2,3,4,20,9,16,17}
    if (arr[k] < arr[i-1])
       return false;
 
    while (k > 1 && k < n)
    {
        if (arr[k] < arr[k-1])
            return false;
        k++;
    }
    return true;
}
 
// Driver Program
int main()
{
    int arr[] = {1, 3, 4, 10, 9, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    checkReverse(arr, n)? cout << "Yes" : cout << "No";
    return 0;
}