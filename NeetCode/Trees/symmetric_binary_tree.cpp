
bool isSymm(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    return isSymm(root1->left, root2->right) && isSymm(root1->right, root2->left);
}
bool isSymmetric(TreeNode<int> *root)
{
    // Write your code here

    if (root == NULL)
        return true;

    return isSymm(root->left, root->right);
}