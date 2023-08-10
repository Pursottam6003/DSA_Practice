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
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {

        // we need to store elements in sorted order on the basis of elements level

        map<int, map<int, multiset<int>>> nodes;
        // also we are doing level order therefore queueu
        queue<pair<TreeNode *, pair<int, int>>> todo;

        todo.push({root,
                   {0,
                    0}});

        // initial vertical and level
        while (!todo.empty())
        {
            auto p = todo.front();
            todo.pop();

            TreeNode *temp = p.first;

            // x->vertical , y->level

            int x = p.second.first, y = p.second.second;

            nodes[x][y].insert(temp->val);

            if (temp->left)
            {
                todo.push({temp->left,
                           {x - 1,
                            y + 1}});
            }

            if (temp->right)
            {
                todo.push({temp->right,
                           {x + 1,
                            y + 1}});
            }
        }

        vector<vector<int>> res;
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};
// another approach

#include <bits/stdc++.h>

void solve(TreeNode<int> *node, int row, int col, map<int, vector<pair<int, int>>> &mpp)
{
    if (!node)
        return;

    mpp[col].push_back({row, node->data});

    solve(node->left, row + 1, col - 1, mpp);
    solve(node->right, row + 1, col + 1, mpp);
}

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> sol;
    map<int, vector<pair<int, int>>> mpp; // map always sort them according to the col numbers

    solve(root, 0, 0, mpp); // assuming root at 0, 0

    for (auto i = mpp.begin(); i != mpp.end(); i++)
    {
        sort(i->second.begin(), i->second.end()); // this will sort the pair vector first according to the row and if row and col are same than according to the value

        for (const pair<int, int> &val : i->second)
        {
            sol.push_back(val.second);
        }
    }

    return sol;
}