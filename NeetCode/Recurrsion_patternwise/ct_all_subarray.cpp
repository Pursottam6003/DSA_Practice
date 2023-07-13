// https://www.codingninjas.com/studio/problems/subarray-sums-i_1467103?leftPanelTab=0
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    // Write Your Code Here
    int res=0;

    unordered_map <int,int> mpp;
    int sum=0;
    int ct=0;
    for(int i=0;i<arr.size();i++)
    {
        sum += arr[i];

        if(sum == k) ct++;

        if(mpp.find(sum - k)!= mpp.end())
        {
            ct += mpp[sum-k];
        }

        mpp[sum]++;
    }
    return ct;
}
