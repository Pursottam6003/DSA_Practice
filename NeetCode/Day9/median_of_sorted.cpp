class Solution {
public:

    double findMedian(vector <int> &num,int n)
    {
        if(n %2 ==0)
        {
            return double(num[n/2]+num[(n/2)-1])/2.0;
        }

        return (double)num[n/2]*1.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(),m = nums2.size();
        vector <int> arr(n+m,0);



        int iter=0;
        int i=0,j=0;

        while(i<n && j<m)
        {
            if(nums1[i] >= nums2[j])
            {
                arr[iter++] = nums2[j++];
            }

            else 
            {
                arr[iter++] = nums1[i++];
            }
        }

        // merge the left array
        while(i < n)
        {
            arr[iter++] = nums1[i++];
        }

        while(j < m)
        {
            arr[iter++] = nums2[j++];
        }

        // now find the median 
        return findMedian(arr,n+m);

    }
};