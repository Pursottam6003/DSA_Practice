#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/


void inorder_trev(BinaryTreeNode<int> *root,vector <int> &res)
{
    if(root == NULL)
    {
        return;
    }
    inorder_trev(root->left,res);
    res.push_back(root->data);
    inorder_trev(root->right,res);
}

void preorder_trev(BinaryTreeNode<int> *root,vector <int> &res)
{
    if(root == NULL)
    {
        return;
    }
    res.push_back(root->data);
    preorder_trev(root->left,res);
    preorder_trev(root->right,res);
}

void postorder_trev(BinaryTreeNode<int> *root,vector <int> &res)
{
    if(root == NULL)
    {
        return;
    }
    postorder_trev(root->left,res);
    postorder_trev(root->right,res);
    res.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.

    vector <int> res;
    vector <vector <int>> ans;

    inorder_trev(root,res);
    ans.push_back(res);

    res.clear();

    preorder_trev(root,res);
    ans.push_back(res);
    
    res.clear();
    postorder_trev(root,res);
    ans.push_back(res);

    return ans;

}