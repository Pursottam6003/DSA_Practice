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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector <vector<int>> res;

        queue <TreeNode *> que;
        // insert into the que 
        que.push(root);

        if(root == NULL) return res;

        while(!que.empty())
        {   
            int n = que.size();
            vector <int> vec;

            for(int i=0;i<n;i++)
            {
                TreeNode *temp = que.front();

                que.pop();
                if(temp == NULL) break;
                vec.push_back(temp->val);
                if(temp->left != NULL) que.push(temp->left);
                if(temp->right != NULL) que.push(temp->right);
            }

            res.push_back(vec);

        }

        return res;
    }
};