/*
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

*/

class Solution 
{
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // checking the minimum sized array one 
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2,nums1);
        // apply binary search in smaller array
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0,high = n1;
        while(low <= high)
        {
            int cut1 = (low+high)/2;
            int cut2  = (n1+n2+1) / 2 - cut1;
            // left side partion
            int left1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2==0 ? INT_MIN : nums2[cut2-1];

            int right1 = cut1==n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2==n2 ? INT_MAX : nums2[cut2];

            if(left1 <= right2 && left2 <= right1)
            {
                // for even 
                if((n1+n2) %2 ==0)
                {
                    return (max(left1,left2) + (min(right1,right2)))/2.0;
                }

                return max(left1,left2);
            }

            else if(left1 > right2)
            {
                high = cut1 -1;
            }


            else 
            {
                low = cut1+1;
            }


        }

        return 0.0;
    }


};