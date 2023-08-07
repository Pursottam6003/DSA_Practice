// https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {

        vector<int> res;
        stack<TreeNode *> stk;

        if (!root)
            return res;

        while (!stk.empty() || root)
        {

            while (root)
            {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();

            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};