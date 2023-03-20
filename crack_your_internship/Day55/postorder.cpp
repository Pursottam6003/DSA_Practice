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

// https://leetcode.com/problems/binary-tree-postorder-traversal/description/
class Solution {
public:
    vector <int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(root ==NULL) return res;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->val);

        return res;
    }
};