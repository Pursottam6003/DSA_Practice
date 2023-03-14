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
// https://leetcode.com/problems/path-sum/description/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root== NULL)
        {
            return false;
        }
        // if it is a leaf node
        if(root->val == targetSum && (root->left == NULL && root->right ==NULL))
        {
            return true;
        }

        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
    }
};