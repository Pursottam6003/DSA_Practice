/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
// https://www.codingninjas.com/studio/problems/boundary-traversal-of-binary-tree_790725?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
bool isLeaf(TreeNode<int> *node)
{
    // we will return true if it is a root node otherwise false

    return (!node->left && !node->right);
}

void addLeftBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *curr = root->left;

    while (curr)
    {
        if (!isLeaf(curr))
        {
            res.push_back(curr->data);
        }

        if (curr->left)
        {
            curr = curr->left;
        }

        else
            curr = curr->right;
    }
}

void addRightBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *curr = root->right;
    vector<int> tmp;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            tmp.push_back(curr->data);
        }

        if (curr->right)
        {
            curr = curr->right;
        }

        else
            curr = curr->left;
    }

    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        res.push_back(tmp[i]);
    }
}
void addLeafNode(TreeNode<int> *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeafNode(root->left, res);
    if (root->right)
        addLeafNode(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> res;

    if (!root)
        return res;
    if (!isLeaf(root))
    {
        res.push_back(root->data);
    }

    addLeftBoundary(root, res);
    addLeafNode(root, res);
    addRightBoundary(root, res);

    return res;
}
