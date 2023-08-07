class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;

        if(!root) return res;
        stk.push(root);

        while(!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();

            res.push_back(curr->val);
            if (curr->right != NULL)
                stk.push(curr->right);
            if (curr->left != NULL)
                stk.push(curr->left);
        }
        return res;
    }
};