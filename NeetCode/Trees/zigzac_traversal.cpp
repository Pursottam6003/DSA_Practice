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

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        vector<vector<int>> ds;
        queue<TreeNode *> que;

        if (root == NULL)
            return ds;

        // first push into the que
        bool flag = true;

        que.push(root);

        while (!que.empty())
        {
            int n = que.size();
            vector<int> temp;
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = que.front();
                que.pop();

                temp.push_back(curr->val);
                if (curr->left)
                    que.push(curr->left);
                if (curr->right)
                    que.push(curr->right);
            }

            if (flag)
            {
                ds.push_back(temp);
                flag = false;
            }

            else
            {
                reverse(temp.begin(), temp.end());
                flag = true;
                ds.push_back(temp);
            }
        }
        return ds;
    }
};

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

vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ds;
    // if root
    if (root == NULL)
        return ds;

    queue<TreeNode<int> *> que;
    que.push(root);

    bool flag = true;
    while (!que.empty())
    {
        int n = que.size();
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            TreeNode<int> *curr = que.front();

            if (curr == NULL)
                break;
            temp.push_back(curr->data);
            que.pop();

            if (curr->left)
                que.push(curr->left);

            if (curr->right)
                que.push(curr->right);
        }

        if (flag)
        {
            flag = false;
        }
        else
        {
            reverse(temp.begin(), temp.end());
            flag = true;
        }

        for (int i = 0; i < temp.size(); i++)
        {
            ds.push_back(temp[i]);
        }
    }

    return ds;
}