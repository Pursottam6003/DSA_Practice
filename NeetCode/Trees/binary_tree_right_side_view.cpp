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

// https://leetcode.com/problems/binary-tree-right-side-view/description/
class Solution
{
public:
    void reversePreorder(TreeNode *root, int lvl, vector<int> &ds)
    {
        if (root == NULL)
            return;

        if (ds.size() == lvl)
        {
            ds.push_back(root->val);
        }
        reversePreorder(root->right, lvl + 1, ds);
        reversePreorder(root->left, lvl + 1, ds);
    }
    vector<int> rightSideView(TreeNode *root)
    {

        vector<int> ds;
        reversePreorder(root, 0, ds);
        return ds;
    }
};