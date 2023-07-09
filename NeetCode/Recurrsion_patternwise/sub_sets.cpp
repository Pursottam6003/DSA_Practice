class Solution {
public:

    void solve(int idx,vector <int> &nums,vector <int> &vec,vector <vector<int>> &res)
    {
        if(idx == nums.size())
        {
            // push into the result 
            res.push_back(vec);
            return;
        }

        vec.push_back(nums[idx]);
        solve(idx+1,nums,vec,res);
        vec.pop_back();
        solve(idx+1,nums,vec,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> vec;
        vector <vector <int>> res;
        solve(0,nums,vec,res);
        return res;
    }
};