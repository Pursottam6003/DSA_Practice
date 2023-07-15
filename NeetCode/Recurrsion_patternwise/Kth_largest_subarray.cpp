
class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        
        vector <int> subArr(N+1,0);
        
        // create an subaray
        
        subArr[0] = 0;
        subArr[1] = Arr[0];
        
        for(int i=2;i<=N;i++)
        {
            subArr[i] = subArr[i-1]+ Arr[i-1];
        }
        
        // min pq 
        priority_queue<int, vector<int>, greater<int> > pq;
        
        // create a priority queue 
        for(int i=1;i<=N;i++)
        {
            for(int j=i;j<=N;j++)
            {
                int  x = subArr[j] - subArr[i-1];
                
                if(pq.size() <K) pq.push(x);
                else 
                {
                    // check the top element 
                    if(pq.top() <x)
                    {
                        pq.pop();
                        pq.push(x);
                    }
                }
            }
        }
        
        return pq.top();
    }
};