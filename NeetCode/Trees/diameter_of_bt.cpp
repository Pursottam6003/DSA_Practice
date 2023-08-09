/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// https://www.codingninjas.com/studio/problems/diameter-of-binary-tree_920552?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
int dfs(TreeNode<int> *root, int &d)
{
    if (root == NULL)
        return 0;

    int left = dfs(root->left, d);
    int right = dfs(root->right, d);

    d = max(d, left + right);

    return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    int res = 0;
    dfs(root, res);
    return res;
}

// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int dfs(TreeNode *root, int &d)
    {
        if (root == NULL)
            return 0;

        int left = dfs(root->left, d);
        int right = dfs(root->right, d);

        d = max(d, left + right);

        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {

        int dimeter = 0;
        dfs(root, dimeter);
        return dimeter;
    }
};