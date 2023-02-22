//Allocate minimum number of pages

//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
class Solution 
{
    public:
    
    int IsPossible(int *A,int n,int pages,int students)
    {
        int cnt=0;
        int sumAllocated =0;
        
        for(int i=0;i<n;i++)
        {
            if(sumAllocated + A[i] > pages)
            {
                cnt++;
                sumAllocated =A[i];
                
                if(sumAllocated > pages) return false;
            }
            else sumAllocated += A[i];
        }
        
        if(cnt <students) return true;
        return false;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M > N) return -1;
        
        // applying binary search 
        int low = A[0];
        int high = 0;
        // to find the minumum value and sum of all pages
        
        for(int i=0;i<N;i++)
        {
            high = high + A[i]; // taking the sum of all the element to se the boundry
            low = min(low,A[i]); // finding the min element in array
        }
        
        // binary search 
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            if(IsPossible(A,N,mid,M))
            {
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};