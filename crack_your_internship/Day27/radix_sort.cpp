// https://practice.geeksforgeeks.org/problems/radix-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
void radixSort(int arr[], int n) 
{ 
   // code here
   // first find the max element in the whole array
   int maxi =0;
   for(int i=0;i<n;i++) maxi = max(maxi,arr[i]);
   
   // calculating the no of iterations we need to perform
   int iterations = log10(maxi)+1;
   
   int mod=10; // using the mod operator to get the element at significant place
   
    while(iterations--)
    {
        // using the ordered map to store the values in sorted order
        map<int, vector<int>> values;
        
        for(int i=0;i<n;i++)
        {   
            // storing the map values in ordered map 
            // such that ordered element remains sorted and stored inside the array
            values[arr[i] % mod].push_back(arr[i]);
        }
        
        int i=0;
        // updating in the array
        for(auto x: values)
        {
            for(auto y: x.second){
                arr[i++] = y;
            }
        }
        
        // updating the modular such aas 10 ,100,1000 
        mod *=10;
    }
    
} 