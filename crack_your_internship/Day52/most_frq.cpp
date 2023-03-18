/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// https://leetcode.com/problems/most-frequent-subtree-sum/description/
class Solution {
public:

    // creating an unordered map 
    unordered_map <int,int> mpp;
    int maxCount=0;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        dfs(root);
        vector <int> res;
        for(auto it :mpp)
        {
            if(it.second == maxCount)
            {
                res.push_back(it.first);
            }
        }
        return res;
    }

    int dfs(TreeNode *root)
    {
        if(root ==NULL) return 0;
        int s = dfs(root->left)+ dfs(root->right) + root->val;
        //store into the map 
        mpp[s]++;
        maxCount = max(maxCount,mpp[s]);
        return s;
    }
};