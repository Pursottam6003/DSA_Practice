

vector <int> getInorder(TreeNode *root)
{
    vector <int> inorder;
    TreeNode *curr = root;

    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            // it is itself is a root 
            inorder.push_back(curr->val);
            curr = curr->right;
        }

        else
        {
            TreeNode *prev = curr->left;

            // go upto you find the right guy 
            while(prev->right && prev->right != curr)
            {
                // and does not be same eleement
                prev = prev->right;
            }

            if(prev->right == NULL)
            {
                // if right does not exits
                prev->right = curr;
                curr = curr->left;
            }

            else 
            {
                prev->right == NULL;
                inorder.push_back(curr.val);
                curr=curr->right;
            }
        }
    }
    return inorder;// returning the vector 
}