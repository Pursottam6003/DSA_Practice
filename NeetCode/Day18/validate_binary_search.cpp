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
// https://leetcode.com/problems/validate-binary-search-tree/submissions/986661918/
class Solution {
public:
    bool isValidBST(TreeNode* root) {

        stack <TreeNode *> stk;

        if(root ==NULL) return true;
        TreeNode *prev = NULL;

        while(!stk.empty() || root)
        {
            while(root)
            {
                stk.push(root);
                // move left 
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(prev != NULL && prev->val >= root->val) return false;
            prev = root;
            root = root->right;
        }
        return true;
    }
};

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

    bool dfs(TreeNode *root,TreeNode*  &prev)
    {
        if(root == NULL) return true;

        if(!dfs(root->left,prev)) return false;
        
        if(prev != NULL && prev->val >= root->val) return false;
        prev = root;
        return dfs(root->right,prev);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = NULL;
        return dfs(root,prev);
    }
};