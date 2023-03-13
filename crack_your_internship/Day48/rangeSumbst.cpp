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

/// @brief https://leetcode.com/problems/range-sum-of-bst/submissions/914197551/
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
    int sum=0;


        if(root->val >=low && root->val <=high)
            sum += root->val;
        
        if(root->left != NULL)
            sum += rangeSumBST(root->left,low,high);
        
        if(root->right != NULL)
            sum += rangeSumBST(root->right,low,high);
        
        return sum;
    }
};