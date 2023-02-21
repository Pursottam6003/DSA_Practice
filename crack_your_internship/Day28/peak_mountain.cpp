// log(n) solution 
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n= arr.size();

        if(n==1) return 0;
        int s=1,e=n-2;


        if(arr[0] > arr[1]) return 0;
        if(arr[n-1] > arr[n-2]) return n-1;

        while(s <=e)
        {
            int mid = s+ (e-s)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            else if(arr[mid] < arr[mid+1]) s = mid+1;
            else if(arr[mid] < arr[mid-1]) e = mid-1;
        }

        return s+1;
    }
};

/*
class Solution {
public:
       int peakIndexInMountainArray(vector<int> A) {
        int l = 0, r = A.size() - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (A[mid] < A[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
*/