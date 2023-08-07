// https://www.codingninjas.com/studio/problems/is-height-balanced-binary-tree_975497?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
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
int depth(TreeNode<int> *root)
{
    if (!root)
        return 0;
    return 1 + max(depth(root->left), depth(root->right));
}
bool isBalancedBT(TreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
        return true;

    int left = depth(root->left);
    int right = depth(root->right);

    return (abs(left - right) <= 1 && isBalancedBT(root->left) && isBalancedBT(root->right));
}

// efficient approach
class Solution
{
public:
    int dfs(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = dfs(root->left);
        if (left == -1)
            return -1;
        int right = dfs(root->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;

        return dfs(root) != -1;
    }
};