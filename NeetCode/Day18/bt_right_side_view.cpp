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

    void dfs(TreeNode *root,int lvl,vector <int> &vec)
    {
        if(root == NULL) return;
        if(vec.size() < lvl) vec.push_back(root->val);
        dfs(root->right,lvl+1,vec);
        dfs(root->left,lvl+1,vec);
    }
    vector<int> rightSideView(TreeNode* root) {
        // create a vector of int 
        vector <int> vec;
        dfs(root,1,vec);
        return vec;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector <int> res;
        queue <TreeNode *> que;


        if(root == NULL) return res;
        que.push(root);

        while(!que.empty())
        {
            int n = que.size();
            for(int i=0;i<n;i++)
            {   
                TreeNode *t = que.front();

                if(i== n-1) res.push_back(t->val);
                que.pop();
                if(t->left != NULL)
                {
                    que.push(t->left);
                }

                if(t->right != NULL)
                {   
                    que.push(t->right);
                }   
             }
        }

        return res;
    }
};