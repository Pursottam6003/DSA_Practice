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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        // check the base condition 
        if(root == NULL) return root;

        // storing the node value into some  temp variable
        TreeNode *temp = root->right;
        // swaping the node values 
        root->right = invertTree(root->left);
        root->left = invertTree(temp);
        // return the root
        return root;
        
    }
};