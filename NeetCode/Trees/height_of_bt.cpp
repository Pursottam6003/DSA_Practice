
// https://www.codingninjas.com/studio/problems/height-of-binary-tree_4609628?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int dfs(TreeNode<int> *root, int res)
{
    if (!root)
        return 0;

    res = 1 + max(dfs(root->left, res), dfs(root->right, res));
    return res;
}
int heightOfBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    int res = 0;
    return dfs(root, res);
}

// another approach

int heightOfBinaryTree(TreeNode<int> *root)
{
    // Write your code here.

    if (!root)
        return 0;
    int left = heightOfBinaryTree(root->left);
    int right = heightOfBinaryTree(root->right);
    return 1 + max(left, right);
}

// https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/
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

// iterative
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int res = 0;
        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty())
        {
            res++;
            int n = que.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *p = que.front();
                que.pop();

                if (p->left != NULL)
                    que.push(p->left);
                if (p->right != NULL)
                    que.push(p->right);
            }
        }
        return res;
    }
};