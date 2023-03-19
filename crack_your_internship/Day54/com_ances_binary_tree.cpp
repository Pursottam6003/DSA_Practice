/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
class Solution {
public:
    TreeNode *dfs(TreeNode *root,TreeNode *p,TreeNode *q)
    {
        if(root==NULL) return NULL;

        if(root == p || root ==q) return root;

        TreeNode *leftNode = dfs(root->left,p,q);
        TreeNode *rightNode = dfs(root->right,p,q);

        if(leftNode != NULL && rightNode != NULL)
        {
            return root;
        }

        // return leftNode == NULL ? rightNode : leftNode;
        return rightNode==NULL?leftNode:rightNode;

        //return root;
     
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return dfs(root,p,q);
        
    }
};