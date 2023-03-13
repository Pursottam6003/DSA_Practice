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
// https://leetcode.com/problems/diameter-of-binary-tree/submissions/914128788/
/*
class Solution {
public:
    int helper(TreeNode *root,int &d)
    {
        if(root == NULL) return 0;
        int ld = helper(root->left, d);
        int rd = helper(root->right, d);
        d=max(d,ld+rd);
        return max(ld,rd)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        helper(root,d);
        return d;
    }
};

*/

class Solution {
public:

    int helper(TreeNode *root,int &d)
    {   // base case
        if(root == NULL) return 0;

        int left = helper(root->left,d);
        int right = helper(root->right,d);

        d = max(d,left+right);

        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int d= 0;
        helper(root,d);
        return d;
    }
};