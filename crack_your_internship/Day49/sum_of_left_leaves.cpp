// https://leetcode.com/problems/sum-of-left-leaves/description/
class Solution 
{
    public:

    int dfs(TreeNode *root,bool isLeft)
    {
        if(!root) return 0;

        if(!root->left && !root->right) return isLeft ? root->val :0;

        return dfs(root->left,true) + dfs(root->right,false);
    }

    int sumofLeftLeaves(TreeNode *root)
    {
        return dfs(root,false);
    }
}