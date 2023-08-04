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
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
class Solution
{
public:
    TreeNode *helper(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return NULL;
        int mid = (l + r) / 2;

        TreeNode *newnode = new TreeNode(nums[mid]);
        // this become the head of tree
        newnode->left = helper(nums, l, mid);
        newnode->right = helper(nums, mid + 1, r);

        return newnode;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {

        // base condition
        if (nums.size() == 0)
            return NULL; // no bst is possible
        // else call a helper functioon
        return helper(nums, 0, nums.size());
    }
};