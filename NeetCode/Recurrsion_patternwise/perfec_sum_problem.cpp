class Solution{

	public:
	
	// solve this problem using recurssion 
	
	int  countPerfectsum(int idx,int *arr,int n,int sum,int currSum)
	{
	    if(idx == n)
	    {
	        if(currSum==sum)
	        {
	            return 1;
	        }
	        return 0;

	    }
	    
	    currSum += arr[idx];
	    int left =  countPerfectsum(idx+1,arr,n,sum,currSum);
	   
	    
	 
	    currSum -= arr[idx];
	    int right = countPerfectsum(idx+1,arr,n,sum,currSum);
	    return left+right;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int res= countPerfectsum(0,arr,n,sum,0);
        return res;
	}
	  
};