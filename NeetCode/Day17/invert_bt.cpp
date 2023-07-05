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
        
        if(root==NULL) return root;
        TreeNode *temp = root->right;
        // change the branch of nodes 
        root->right = invertTree(root->left);
        root->left = invertTree(temp);

        return root;
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
    TreeNode* invertTree(TreeNode* root) {
        stack <TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode *tempRoot = stk.top();
            stk.pop();
            if(tempRoot){
                TreeNode *tmp = tempRoot->right;
                tempRoot->right = tempRoot->left;
                tempRoot->left = tmp;

                stk.push(tempRoot->left);
                stk.push(tempRoot->right);
            }
        }
        return root;
    }
};