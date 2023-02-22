/*
class Solution {
public:

    
    void merge(vector<pair<int,int>> &nums,int low,int mid ,int high,vector <int> &cnt)
    {
        int total = 0;
        int j=mid+1;

        // main point for calculating the reverrse pairs
        vector <int> temp;
        int left = low,right =mid+1;

        // for(int i=low;i<=mid;i++)
        // {
        //     if(nums[i].first > nums[j].first && j <= high)
        //     {
        //         j++;
        //     }
        //     int total = (j-(mid+1));
        //     cnt[nums[i].second] += total;
        // }

        while(left <= mid && right <= high)
        {
            if(nums[left].first <= nums[right].first) 
            {
                temp.push_back(nums[right++].first);
            }
            else 
            {
                cnt[nums[left].second] += high-right+1;
                temp.push_back(nums[left++].first);
            }
        }

        while(left <= mid) temp.push_back(nums[left++].first);
        while(right <= high) temp.push_back(nums[right++].first);

        // copying into the other array
        for(int i=low;i<=high;i++)
        {
            nums[i].first = temp[i-low];
        }
       // return total;
    }
    void MergeSort(vector <pair<int,int>> &nums, int low,int high,vector<int> &cnt)
    {
        if(low >= high) return;
        int mid = (low+high)/2;
        
        MergeSort(nums,low,mid,cnt);
        MergeSort(nums,mid+1,high,cnt);
        merge(nums,low,mid,high,cnt);
    }

    
    vector<int> countSmaller(vector<int>& arr) {
        
        vector <int> res(arr.size(),0);
        
        vector <pair<int,int>> nums;
        for(int i=0;i<arr.size();i++)
        {
            nums.push_back({arr[i],i});
        }

        MergeSort(nums,0,nums.size()-1,res);
        return res;
    }
};
*/


class Solution 
{
    public:

    void merge(vector <int> &count,vector <pair<int,int>> &v,int left,int mid,int right)
    {
        vector<pair<int,int>> temp(right-left+1);

        int i= left;
        int j = mid+1;
        int k =0;

        while(i <= mid && j <= right)
        {
            if(v[i].first <= v[j].first)
            {
                temp[k++] = v[j++]; // choosing the bigger on to select in decending order
            }

            else 
            {
                count[v[i].second] += right-j+1;
                temp[k++] = v[i++];
            }
        }

        while(i<=mid)
        {
            temp[k++] = v[i++];
        }
        while(j <= right)
        {
            temp[k++] = v[j++];
        }

        for(int i=left;i<=right;i++)
        {
            v[i] = temp[i-left];
        }
    }


    void mergeSort(vector<int> &count, vector<pair<int,int>> &v, int left, int right){
        
        
        if(left<right){
            int mid = left + (right-left)/2;
            mergeSort(count, v, left, mid);
            mergeSort(count, v, mid+1, right);
            merge(count, v, left, mid, right);
        }
        
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            v[i] = p;
        }
        
        
        vector<int> count(n, 0);
        mergeSort(count, v, 0, n-1);
        return count;
        
    }

};