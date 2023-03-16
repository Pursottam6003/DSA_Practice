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
/// https://leetcode.com/problems/subtree-of-another-tree/description/
class Solution {
public:

    bool isSame(TreeNode *root,TreeNode *subTree)
    {
        if(root ==NULL && subTree==NULL) return true;
        if(root ==NULL || subTree==NULL) return false;

        if(root->val != subTree->val) return false;

        return isSame(root->left,subTree->left) && isSame(root->right , subTree->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root ==NULL) return false;

        if(isSame(root,subRoot))
        {   
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);

    }
};

/*
class Solution
{
    public:    
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        string tree1, tree2;        
        buildPreorder(root, tree1);
        buildPreorder(subRoot, tree2);
        
        if (tree1.find(tree2) == string::npos)
            return false;        
        return true;
    }
    
    void buildPreorder(TreeNode* root, string& s)
    {
        if (root == nullptr)
            s += ",#";
        else
        {
            s += "," + to_string(root->val);
            buildPreorder(root->left, s);        
            buildPreorder(root->right, s);
        }
    }
};
*/