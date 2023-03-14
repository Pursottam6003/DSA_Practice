/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/772053339/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root->val > p->val && root->val >q->val)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        
        else if(root->val <p->val && root->val <q->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        
        return root;
    }
};