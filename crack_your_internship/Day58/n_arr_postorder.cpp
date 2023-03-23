/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// recurssive 
class Solution {
public:

    void traverse(Node *root, vector <int> &res)
    {
        if(root ==NULL) return;

        for(Node *child: root->children)
        {
            traverse(child,res);
        }
        res.push_back(root->val);
    }
    vector <int> postorder(Node *root)
    {
        vector <int> res;
        traverse(root,res);
        
        return res;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        // return an empty vector 
        if(root ==NULL) return {};

        stack <Node *> stk;
        vector <int> res;

        stk.push(root);
        while(!stk.empty())
        {
            Node *temp = stk.top();
            stk.pop();
            for(int i=0;i< temp->children.size();i++)
            {
                stk.push(temp->children[i]);
            }
            res.push_back(temp->val);
        }

        reverse(res.begin(),res.end());
        return res;
    }
};