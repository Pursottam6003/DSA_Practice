/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
m * };
 */

//https://leetcode.com/problems/merge-two-binary-trees/description/
class Solution {
public:

    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // base case
        if(root1==NULL)
        {
            return root2;
        }

        if(root2==NULL)
        {
            return root1;
        }

        // main condition 

        TreeNode *mergedTree = new TreeNode((root1 ? root1->val :0) + (root2 ? root2->val :0));

        mergedTree->left = mergeTrees(root1->left,root2->left);
        mergedTree->right = mergeTrees(root1->right,root2->right);

        return mergedTree;
    }
};