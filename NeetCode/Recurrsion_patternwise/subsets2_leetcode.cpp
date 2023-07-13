// https://leetcode.com/problems/subsets-ii/description/
class Solution {
public:
    void recurssion(int ind,vector <int> &arr,vector <int> &ds,vector <vector <int>> &res)
    {
        // base case changed 
        res.push_back(ds);
     

        for(int i=ind;i<arr.size();i++)
        {
            if(i != ind && arr[i] == arr[i-1]) continue;
            ds.push_back(arr[i]);
            recurssion(i+1,arr,ds,res);
            ds.pop_back();
        }
 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector <vector<int>> res;
        vector <int> ds;
        // sort the input array 
        sort(arr.begin(),arr.end());
        recurssion(0,arr,ds,res);
        return res;
    }
};