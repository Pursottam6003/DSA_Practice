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

/// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
class Solution {
public:

    int mini=INT_MAX;
    int prev=-1;
    int getMinimumDifference(TreeNode* root) {
        
        if(root->left != NULL) getMinimumDifference(root->left);

        if(prev >=0) mini = min(mini,root->val - prev);

        // updating prev 
        prev = root->val;

        if(root->right != NULL) getMinimumDifference(root->right);

        return mini;

    }
};