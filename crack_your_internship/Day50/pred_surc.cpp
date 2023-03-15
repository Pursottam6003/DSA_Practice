
// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
// It sets pre and suc as predecessor and successor respectively
void prede(Node* root, Node*& pre, int key)
{
    while(root!=0)
    {
        if(key<=root->key)
        {
            root=root->left;
        }
        else
        {
            pre=root;
            root=root->right;
        }
    }
}
void succe(Node* root, Node*& suc, int key)
{
    while(root!=0)
    {
        if(key>= root->key)
        {
            root=root->right;
        }
        else
        {
            suc=root;
            root=root->left;
        }
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    prede(root,pre,key);
    succe(root,suc,key);
}