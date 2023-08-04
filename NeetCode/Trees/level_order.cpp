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
// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        vector<vector<int>> res;

        // create a queue
        queue<TreeNode *> que;
        if (root == NULL)
            return res;
        // push the element
        que.push(root);

        while (!que.empty())
        {
            vector<int> temp;
            // find the size
            int n = que.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *t = que.front();
                if (t == NULL)
                    break;
                temp.push_back(t->val);
                que.pop();
                if (t->left)
                    que.push(t->left);
                if (t->right)
                    que.push(t->right);
            }
            res.push_back(temp);
        }

        return res;
    }
};