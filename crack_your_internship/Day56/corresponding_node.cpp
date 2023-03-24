/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/

/*
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(original == NULL) return NULL;

        if(original == target) return cloned;

        TreeNode *left = getTargetCopy(original->left,cloned->left,target);

        // if left exist
        if(left !=NULL) return left;

        return getTargetCopy(original->right,cloned->right,target);
    }
};
*/

// DFS approach 

class Solution {
public:
    /*
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(original == NULL) return NULL;

        if(original == target) return cloned;

        TreeNode *left = getTargetCopy(original->left,cloned->left,target);

        // if left exist
        if(left !=NULL) return left;

        return getTargetCopy(original->right,cloned->right,target);
    }
    */

    void dfs(TreeNode * root,TreeNode *target,TreeNode * &res)
    {   
        if(!root) return;
        // if found store into the res variable and return
        if(root->val == target->val) 
        {
            res = root;
            return;
        }
        // if not found move towards left
        dfs(root->left,target,res);
        // move towards right 
        dfs(root->right,target,res);
        // can return 
        return;
        
    }
    TreeNode *getTargetCopy(TreeNode *original,TreeNode *cloned, TreeNode *target)
    {   
        // creating one res variable which will stor ehte value of particular 
        // node at which it will start 
        TreeNode *res;
        dfs(cloned,target,res);
        return res;
        
    }
};

// Not recommended BFS approach 
  TreeNode *getTargetCopy(TreeNode *original,TreeNode *cloned, TreeNode *target)
    {   
        TreeNode *res;
        queue <TreeNode *> que;
        if(cloned == target) return cloned;
        que.push(cloned);
        while(!que.empty())
        {

            TreeNode *temp = que.front();
            que.pop();

            if(temp->val == target->val) res= temp;
            
            if(temp ->left) 
            {
                que.push(temp->left);
            }
            if(temp->right)
            {
                que.push(temp->right);
            }
        }

        return res;
    }

