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
// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/submissions/920175476/
class Solution {
public:
    /*
    int first_one =INT_MAX;
    int second=INT_MAX;
    int findSecondMinimumValue(TreeNode* root) {

        if(root == NULL) return -1;

        if(first_one > root->val)
        {
            second = first_one;
            first_one = root->val;
        }

        if(second >= root->val && root->val > first_one)
        {
            second = root->val;
        }
        findSecondMinimumValue(root->left);
        findSecondMinimumValue(root->right);

        return second==INT_MAX ? -1 : second;
    }
    */

    int dfs(TreeNode *root,int first)
    {
        if(root ==NULL) return -1;

        int left = dfs(root->left,first);
        int right  = dfs(root->right,first);

        if(root->val != first) return root->val;

        if(left ==-1) return right;
        if(right ==-1) return left;
        return min(left,right);
    }
    int findSecondMinimumValue(TreeNode *root)
    {
        return dfs(root,root->val);
    }
};