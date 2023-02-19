// https://practice.geeksforgeeks.org/problems/ceil-the-floor2802/1
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    
    pair<int,int> myres;
    // sort the array
    //sort(arr,arr+n);
    
    int myfloor=-1,myceil=INT_MAX;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i] <=x)
        {
            myfloor = max(myfloor,arr[i]);
        }
        if(arr[i] >=x)
        {
            myceil = min(myceil,arr[i]);
        }
    }
    
    if(myceil==INT_MAX)
    {
        myceil =-1;
    }

    
    myres.first = myfloor;
    myres.second = myceil;
    
    return myres;
    
}