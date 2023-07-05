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

 //https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
        stack <TreeNode *> stk;
        while(!stk.empty() || root)
        {
            while(root)
            {
                stk.push(root);
                // move towards left as possible 
                root = root->left;
            }

            // now updat the root with value 
            root = stk.top();
            stk.pop();
            // pop the element 
            if(--k ==0) break;
            root = root->right;
        }

        return root->val;
    }
};