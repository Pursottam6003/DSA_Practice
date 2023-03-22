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
// https://leetcode.com/problems/find-mode-in-binary-search-tree/submissions/920273953/
class Solution {
public:

    int maxFreq =0, currFreq = 0, precursor = INT_MIN;
    vector <int> res;

    void inorderTraversal(TreeNode *root)
    {
        if(root == NULL) return; /// stop condition 
        inorderTraversal(root->left);

        if(precursor == root->val) currFreq++;
        else currFreq =1;

        if(currFreq > maxFreq)
        {
            // current nod value has higher frequency than 
            res.clear();
            maxFreq = currFreq;
            res.push_back(root->val);
        }

        else if(currFreq == maxFreq)
        {
            res.push_back(root->val);
        }

        precursor = root->val; // updating 
        inorderTraversal(root->right);
    }
 
    vector<int> findMode(TreeNode* root) {
        inorderTraversal(root);
        return res;
    }


};