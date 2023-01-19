 
/*
Brute force
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        vector <int> temp; // temproray array 
        while(i< m && j < n)
        {
            if(nums1[i] > nums2[j])
            {
                temp.push_back(nums2[j]);
                j++;
            }
            else
            {
                temp.push_back(nums1[i]);
                i++;
            }
        }

        if(i != m)
        {
            while(i != m)
            {
                temp.push_back(nums1[i]);
                i++;
            }
        }

        else if(j != n) 
        {
            while(j != n)
            {
                temp.push_back(nums2[j]);
                j++;
            }            
        }

        int s = temp.size();

        for(int i=0;i<s;i++)
        {
            nums1[i] = temp[i];
        }
    }
}; */

// Efficient approach 
class Solution 
{
    public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){

        int i= m-1,j = n-1;
        int updatedSize = (m+n)-1;

        while(i>=0 && j>=0)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[updatedSize] = nums1[i];
                i--;
                updatedSize--;
            }

            else 
            {
                nums1[updatedSize--] = nums2[j--];
            }
        }
        // if any array is left then we insert the remainig eleements

        while(i>=0)
        {
            nums1[updatedSize--] = nums1[i--];
        }

        while(j>=0)
        {
            nums1[updatedSize--] = nums2[j--];
        }

    }
};