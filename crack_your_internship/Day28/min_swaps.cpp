// https://practice.geeksforgeeks.org/problems/minimum-swaps/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	     vector <pair<int,int>> v;
	     int n = nums.size();
	     
	     for(int i=0;i<n;i++)
	     {
	         v.push_back({nums[i],i});
	     }
	     
	     // 10 19  6  3  5   (10,0), (19,1) (6,2) (3,3) (5,4)

	     // (3,3) (5,4) (6,2) (10,0) (19,1) // sorted v
	     // (10,0) (5,4) (6,2) (3,3) (19,1)
	     
	     // 
	     int ans=0;
	     sort(v.begin(),v.end());
	     
	     for(int i=0;i<n;i++)
	     {
	         if(i == v[i].second) continue;
	         
	         else 
	         {
	             ans++;
	             swap(v[i],v[v[i].second]);
	             i--; // this is done to check the current element is swapped 
	         }
	     }
	     return ans;
	}
};