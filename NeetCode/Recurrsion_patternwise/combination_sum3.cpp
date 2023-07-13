// https://leetcode.com/problems/combination-sum-iii/description/
class Solution {
public:

    void recursion(int idx,int n,int k,int sum,vector <int> &ds,vector <vector<int>> &res)
    {
        if(sum ==n && k==0)
        {
            // base case 
            res.push_back(ds);
            return;
        }
        /// check if the sum exceeds the target
        if(sum >n) return;
    

        for(int i=idx;i<=9;i++)
        {   
            if(i > n) break;
            ds.push_back(i);
            recursion(i+1,n,k-1,sum+i,ds,res);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> ds;
        vector <vector<int>> res;

        recursion(1,n,k,0,ds,res);
        return res;
    }
};