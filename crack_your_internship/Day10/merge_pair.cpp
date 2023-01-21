// https://leetcode.com/problems/reverse-pairs/description/
class Solution {
public:

    int merge(vector <int> &nums,int low,int mid,int high)
    {   
        int total=0;
        int j= mid+1;

        // main point  for calculting the reverse pairs 

        for(int i=low;i<=mid;i++)
        {
            while(j<= high && nums[i] > 2LL *nums[j])
            {
                j++;
            }

            total += (j- (mid+1));
        }


        vector <int> temp;
        int left = low,right=mid+1;

        while(left <= mid && right <= high)
        {
            if(nums[left] <= nums[right])
            {
                temp.push_back(nums[left++]);
            }

            else 
            {
                temp.push_back(nums[right++]);
            }
        }

        while(left <= mid) temp.push_back(nums[left++]);

        while(right <= high) temp.push_back(nums[right++]);

        // copying into the other array

        for(int i=low;i<=high;i++){
            nums[i] = temp[i-low];
        }

        return total;
    }


    int MergeSort(vector <int> &nums,int low,int high)
    {
        if (low >= high) return 0;

        int mid = (low+high)/2;

        int inv = MergeSort(nums,low,mid);

        inv += MergeSort(nums,mid+1,high);
        inv += merge(nums,low,mid,high);

        return inv;
    }
  
    int reversePairs(vector<int>& nums) {
        // approach 
        // we first try to break the  array sing merge sort and 
        // while mergeing counting hte reverse pair is 
        // available 
        return MergeSort(nums,0,nums.size()-1);
    }
};