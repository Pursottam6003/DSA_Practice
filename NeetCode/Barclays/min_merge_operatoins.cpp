#include <bits/stdc++.h>
using namespace std;

// Returns minimum number of count operations    
// required to make arr[] palindrome


int expandFromMiddle(string s, int left, int right){
        if(s.length() == 0 || left > right) return 0;
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }

string longestPalindrome(string s) {
        
        int n = s.length();
        if(n == 0) return "";
        int start = 0, end = 0;
        for(int i = 0; i < n; i++){
            int len1 = expandFromMiddle(s, i, i);
            int len2 = expandFromMiddle(s, i, i+1);
            int len = max(len1, len2);
            if(len > end - start){
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
    return s.substr(start, end-start+1);    
}

int findMinOps(int arr[], int n)
{
	int ans = 0; // Initialize result

	// Start from two corners
	for (int i=0,j=n-1; i<=j;)
	{
		// If corner elements are same,
		// problem reduces arr[i+1..j-1]
		if (arr[i] == arr[j])
		{
			i++;
			j--;
		}

		// If left element is greater, then
		// we merge right two elements
		else if (arr[i] > arr[j])
		{
			// need to merge from tail.
			j--;
			arr[j] += arr[j+1] ;
			ans++;
		}

		// Else we merge left two elements
		else
		{
			i++;
			arr[i] += arr[i-1];
			ans++;
		}
	}

	return ans;
}

int main()
{
    int arr[] = {15, 10, 15, 34, 25, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Count of minimum operations is "
        << findMinOps(arr, n) << endl;

    cout<<"Print the resultent pallindrome array: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}