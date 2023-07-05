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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL && q==NULL) return true; // at the end 

        else if(p==NULL || q==NULL) return false;

        else if(p->val != q->val) return false;

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
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

// Iterative 
class Solution {
public:
    // bool isSameTree(TreeNode* p, TreeNode* q) {
        
    //     if(p==NULL && q==NULL) return true; // at the end 

    //     else if(p==NULL || q==NULL) return false;

    //     else if(p->val != q->val) return false;

    //     return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    // }

    bool isSameTree(TreeNode *p,TreeNode *q)
    {
        stack <pair<TreeNode *,TreeNode *>> stk;
        stk.push({p,q});

        while(!stk.empty())
        {
            auto [node1,node2] = stk.top();
            stk.pop();

            if(node1 == NULL && node2 == NULL) continue;

            else if(!node1 || !node2 || node1->val != node2->val) return false;

            stk.push({node1->left,node2->left});
            stk.push({node1->right,node2->right});
        }
        return true;
    }
};