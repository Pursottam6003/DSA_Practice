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
// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/
class Solution {
public:
    void reverseNodes(TreeNode *node1,TreeNode *node2,int level)
    {   
        if(node1 == NULL || node2== NULL) return ;

        if(level &1)
        {
            //swaping the valies
            int t = node2->val;
            node2->val = node1->val;
            node1->val = t;
        }

        reverseNodes(node1->left,node2->right,level+1);
        reverseNodes(node1->right,node2->left,level+1);
        return ;
       
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        reverseNodes(root->left,root->right,1);
        return root;
    }
};