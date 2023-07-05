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
 // https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
class Solution {
public:
    int res=0;

    void dfs(TreeNode *root,int val)
    {
        if(root == NULL) return;

        if(root->val >= val) res++;
        dfs(root->left,max(val,root->val));
        dfs(root->right,max(val,root->val));
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return res;
        dfs(root,root->val);

        return res;
    }
};