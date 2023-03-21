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
// https://leetcode.com/problems/increasing-order-search-tree/description/
class Solution {
public:

    void dfs(TreeNode *root, vector<int> &res )
    {
        if(root==NULL) return;
        dfs(root->left,res);
        res.push_back(root->val);
        dfs(root->right,res);
    }
    TreeNode* increasingBST(TreeNode* root) {

        // inorder traversal karo 
        if(root == NULL) return NULL;

        // increasingBST(root->left);
        vector<int> res;
        dfs(root,res);

        TreeNode *newNode = root;
        

        for(int i=0;i<res.size();i++)
        {
            TreeNode *t = new TreeNode(res[i]);
            newNode->left=NULL;
            newNode->right= t;
            newNode = t;
        }

        return root->right;


        
    }
};