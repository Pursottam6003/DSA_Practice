
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};
Make a set of all nodes [Add 0 in the set so that if we encounter 1 the we can handle that]
traverse through the tree and for every leaf node check if leaf-1 and leaf+1 values are present in the set or not.
If both present, then that leaf node is a dead end; else not
recursively check for both subtrees if not a leaf node. if any one of subtree returns true, then return true.
*/

/*You are required to complete below method */

// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

void inorder(Node *root,unordered_set<int> &s)
{
    if(root == NULL) return;
    
    inorder(root->left,s);
    s.insert(root->data);
    inorder(root->right,s);
}

bool check(Node *root,unordered_set <int> &s)
{
    if(root == NULL) return false;
    
    if(root->left == NULL && root->right ==NULL)
    {
        // we encounter a leaf node
        int tp = root->data;
        
        if(s.count(tp-1) && s.count(tp+1)) return true;
    }
    
    return check(root->left,s) || check(root->right,s);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    unordered_set <int> s;
    s.insert(0);
    
    inorder(root,s);
    
    return check(root,s);
}