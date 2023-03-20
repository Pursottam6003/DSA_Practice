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
//https://leetcode.com/problems/binary-tree-tilt/description/

class Solution {
public:

    int dfs(TreeNode* root,int &res) 
    {
        if(!root) return 0;
        int left = dfs(root->left,res);
        int right = dfs(root->right,res);

        res += abs(left-right);
        return left+right+root->val;
    }
 

    int findTilt(TreeNode* root) {
        int res=0;
        dfs(root,res);
        return res;
        // recur(root,res);
            
    }
};