/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    // Write your code here.

    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->data == root2->data && identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right));
}

// iterative

//  https://leetcode.com/problems/same-tree/submissions/
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
class Solution
{
public:
    // bool isSameTree(TreeNode* p, TreeNode* q) {

    //     if(p==NULL && q==NULL) return true; // at the end

    //     else if(p==NULL || q==NULL) return false;

    //     else if(p->val != q->val) return false;

    //     return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    // }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        stack<pair<TreeNode *, TreeNode *>> stk;
        stk.push({p, q});

        while (!stk.empty())
        {
            auto [node1, node2] = stk.top();
            stk.pop();

            if (node1 == NULL && node2 == NULL)
                continue;

            else if (!node1 || !node2 || node1->val != node2->val)
                return false;

            stk.push({node1->left, node2->left});
            stk.push({node1->right, node2->right});
        }
        return true;
    }
};