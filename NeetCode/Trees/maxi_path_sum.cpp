/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// https://www.codingninjas.com/studio/problems/maximum-sum-path-of-a-binary-tree._1214968?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
int getHeight(BinaryTreeNode<int> *root, int &sum)
{
    if (!root)
        return 0;

    int left = max(0, getHeight(root->left, sum));
    int right = max(0, getHeight(root->right, sum));

    sum = max(sum, left + right + root->data);

    return max(left, right) + root->data;
}
int maxPathSum(BinaryTreeNode<int> *root)
{
    // Write your code here
    int res = 0;

    getHeight(root, res);
    return res;
}
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
// https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/
class Solution
{
public:
    int dfs(TreeNode *root, int &sum)
    {
        if (!root)
            return 0;

        int left = max(0, dfs(root->left, sum));
        int right = max(0, dfs(root->right, sum));

        sum = max(sum, left + right + (root->val));

        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode *root)
    {
        int s = INT_MIN;

        dfs(root, s);
        return s;
    }
};