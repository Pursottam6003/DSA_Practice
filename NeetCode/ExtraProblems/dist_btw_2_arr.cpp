// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/description/
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)   {
        
        int res=0;
        for(int i=0;i<arr1.size();i++)
        {
            int val = arr1[i];

            for(int j=0;j<arr2.size();j++)
            {
                int dist = abs(val - arr2[j]);

                if(dist<= d) break;

                if(j== arr2.size()-1) res++; 
            }
        }

        return res;
    }
};

// efficient solution

class Solution {
public:

   
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // sort the second array 

        sort(arr2.begin(),arr2.end());

        int res=0;
        for(int i=0;i<arr1.size();i++)
        {
            int num = arr1[i];

            int l=0, r = arr2.size()-1, x = arr1[i]-d, y = arr1[i]+d;
            // the value should reange between x and y 
            while(l <=r )
            {
                int mid = (l+r)/2;

                if(arr2[mid] < x)
                {
                    // increment low 
                    l = mid+1;
                }

                else if(arr2[mid] > y)
                {
                    // it should not exceed the range 
                    r = mid-1;
                }

                else
                {
                    res++;
                    break;
                }
            }
        }

        return arr1.size()-res;
    }
};