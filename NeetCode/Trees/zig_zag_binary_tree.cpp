#include <bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
// https://www.codingninjas.com/studio/problems/zigzag-binary-tree-traversal_920532?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> res;
    if (root == NULL)
        return res;

    queue<TreeNode<int> *> que;
    que.push(root);

    int f = 1;
    while (!que.empty())
    {
        int n = que.size();
        vector<int> t;
        for (int i = 0; i < n; i++)
        {
            TreeNode<int> *temp = que.front();

            if (temp == NULL)
                break;
            t.push_back(temp->data);
            que.pop();

            if (temp->left)
            {
                que.push(temp->left);
            }

            if (temp->right)
            {
                que.push(temp->right);
            }
        }

        if (f % 2 == 0)
            reverse(t.begin(), t.end());

        for (int i = 0; i < t.size(); i++)
        {
            res.push_back(t[i]);
        }
        f = !f;
    }

    return res;
}