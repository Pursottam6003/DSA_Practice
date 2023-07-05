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

/*
class Solution {
public:

    int maxDepth(TreeNode* root) {
        return dfs(root,0);
    }

private:

    int  dfs(TreeNode *root,int res)
    {
        if(root==NULL) return 0;

        res += 1+max(dfs(root->left,res),dfs(root->right,res));
        return res;
    }
};

*/
class Solution 
{
    public:
    int maxDepth(TreeNode *root)
    {
        if(!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);

        return 1+max(maxLeft,maxRight);
    }
};


class Solution {
public:

    int maxDepth(TreeNode* root) {
        return dfs(root,0);
    }

private:

    int  dfs(TreeNode *root,int res)
    {
        if(root==NULL) return 0;

        res += 1+max(dfs(root->left,res),dfs(root->right,res));
        return res;
    }
};


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

    int res=0;
    int maxDepth(TreeNode* root) {
        
        if(root == NULL) return 0;
 
        res = max(1+maxDepth(root->left), 1+maxDepth(root->right));

        }
        return res;

    }
};

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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int res=0;
        queue <TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            res++;

            for(int i=0,n=que.size();i<n;i++)
            {
                TreeNode *p = que.front();
                que.pop();

                if(p->left != NULL) 
                    que.push(p->left);
                if(p->right != NULL)
                    que.push(p->right);
            }
        }
        return res;
    }
};