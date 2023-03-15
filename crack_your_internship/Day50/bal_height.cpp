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
/*
// 
class Solution {
public:

    int depth(TreeNode *root)
    {
        if(root == NULL) return 0;

        return max(depth(root->left), depth(root->right))+1;
    }

    bool isBalanced(TreeNode* root) {

        if(root== NULL)
        {
            return true;
        }

        int left = depth(root->left);
        int right = depth(root->right);

        return abs(left-right) <=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
*/

class Solution
{
    public:
    int Balheight(TreeNode *root)
    {
        if(root == NULL) return 0;

        int left = Balheight(root->left);

        if(left == -1) return -1;

        int right = Balheight(root->right);

        if(right == -1) return -1;

        if(abs(left-right) > 1) return -1;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode *root)
    {
        return Balheight(root) != -1;
    }
};