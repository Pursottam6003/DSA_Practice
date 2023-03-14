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

// https://leetcode.com/problems/binary-tree-paths/description/
class Solution {
public:
    
    void dfs(TreeNode *root, vector<string> &res,string str)
    {
        if(root->left == NULL && root->right == NULL)
        {
            res.push_back(str);
            return;
        }

        if(root->left)
        {  
            // again calling funciont 
            dfs(root->left,res, str+"->"+ to_string(root->left->val) );
        }

        if(root->right)
        {
            dfs(root->right,res,str+"->"+ to_string(root->right->val));
        }
       
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> res;

        dfs(root,res, to_string(root->val));

        return res;
    }
};