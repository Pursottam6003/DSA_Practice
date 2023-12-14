#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int *arr,int n)
{
    // insertion sort 
    int j,key;
    for(int i=1;i<n;i++)
    {
        j = i-1;
        key =arr[i];

        while(j >=0 && arr[j] >key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

}

int select(int arr[], int i,int n)
{
    // code here such that selectionSort() sorts arr[]
    int mini_idx = i;
    
    while(i < n)
    {
        if(arr[i] < arr[mini_idx])
            mini_idx = i;
        i++;
    }
    return mini_idx;
}
    
void selectionSort(int arr[], int n)
{
    //code here
    for(int i=0;i<n;i++)
    {
        int mini_idx = select(arr,i,n);
        
        if(mini_idx != i)
            swap(arr[mini_idx],arr[i]);
    }
    
}
 
void bubble_sort(int *arr,int n)
{   
    bool swap_flag;
    for(int i=0;i<n-1;i++)
    {   swap_flag = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] >= arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swap_flag = true;
            }
        }
        // ie the elements were already sorted
        // If no two elements were swapped
        // by inner loop, then break
        if(swap_flag == false) break;
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the unosrted elements"<<endl;
    for(int i=0;i<n;i++) cin>>a[i];

    // sort function 
    // bubble_sort(a,n);
    insertion_sort(a,n);
    cout<<"sorted array"<<endl;
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}