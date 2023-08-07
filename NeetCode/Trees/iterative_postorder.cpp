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

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> stk;
        TreeNode *prev = NULL;
        vector<int> res;

        while (root || !stk.empty())
        {
            if (root)
            {
                stk.push(root);
                root = root->left;
            }

            else
            {
                TreeNode *node = stk.top();

                if (node->right && prev != node->right)
                {
                    root = node->right;
                }
                else
                {
                    res.push_back(node->val);
                    prev = node;
                    stk.pop();
                }
            }
        }
        return res;
    }
};