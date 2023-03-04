// https://practice.geeksforgeeks.org/problems/insertion-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution
{
    public:
    void insert(int arr[], int j)
    {
        //code here
        while(j>0 && arr[j] < arr[j-1])
        {   
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        
        for(int i=1;i<n;i++)
        {
            int j=i;
            insert(arr,j);
        }
    }
};