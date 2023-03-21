/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/
class Solution {
public:

 
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(original == NULL) return NULL;

        if(original == target) return cloned;

        TreeNode *left = getTargetCopy(original->left,cloned->left,target);

        // if left exist
        if(left !=NULL) return left;

        return getTargetCopy(original->right,cloned->right,target);
    }
};