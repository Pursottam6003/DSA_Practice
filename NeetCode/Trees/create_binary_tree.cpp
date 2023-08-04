/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

// recursive approach
Node *helper(int i, int n, vector<int> &nums)
{
    if (i >= n)
        return NULL;

    Node *newNode = new Node(nums[i]);

    newNode->left = helper(2 * i + 1, n, nums);
    newNode->right = helper(2 * i + 2, n, nums);
    return newNode;
}

Node *createTree(vector<int> &arr)
{

    if (arr.size() == 0)
        return NULL;

    return helper(0, arr.size(), arr);
}

// iterative approach BFS using queue

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

Node *createTree(vector<int> &arr)
{
    // Write your code here.

    queue<Node *> que;
    Node *root = new Node(arr[0]);
    que.push(root);

    int i = 0;

    while (!que.empty() && 2 * i + 2 <= arr.size())
    {
        Node *temp = que.front();
        que.pop();

        // create the left child node with the value from the corresponding
        Node *left = new Node(arr[2 * i + 1]);
        temp->left = left;
        que.push(left);

        // create the right child nod with the valuf rom the correcspoiding
        Node *right = new Node(arr[2 * i + 2]);
        temp->right = right;
        que.push(right);
        i++;
    }
    return root;
}