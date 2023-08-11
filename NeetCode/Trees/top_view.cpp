// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Your code here
        vector<int> res;
        map<int, int> mpp;
        queue<pair<Node *, int>> que;

        // check if root is null or what
        if (!root)
            return res;

        // do the level order traversal

        que.push({root, 0});

        while (!que.empty())
        {
            auto a = que.front();
            que.pop();
            Node *curr = a.first;

            if (curr->left)
            {
                que.push({curr->left, a.second - 1});
            }

            if (curr->right)
            {
                que.push({curr->right, a.second + 1});
            }

            if (mpp.find(a.second) != mpp.end())
            {
                continue;
            }

            else
            {
                mpp[a.second] = curr->data;
            }
        }

        for (auto it : mpp)
        {
            res.push_back(it.second);
        }

        return res;
    }
};