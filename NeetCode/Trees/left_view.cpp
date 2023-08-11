/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// https://www.codingninjas.com/studio/problems/left-view-of-binary-tree_625707?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
#include <bits/stdc++.h>
void Preorder(BinaryTreeNode<int> *root, int lvl, vector<int> &ds)
{
    if (root == NULL)
        return;

    if (ds.size() == lvl)
    {
        ds.push_back(root->data);
    }
    Preorder(root->left, lvl + 1, ds);
    Preorder(root->right, lvl + 1, ds);
}

vector<int> printLeftView(BinaryTreeNode<int> *root)
{
    // Write your code here

    vector<int> ds;
    Preorder(root, 0, ds);

    return ds;
}