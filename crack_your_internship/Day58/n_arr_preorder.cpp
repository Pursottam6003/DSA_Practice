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
*/

/**
 * 
 * class Solution {
private:
    void travel(Node* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        
        result.push_back(root -> val);
        for (Node* child : root -> children) {
            travel(child, result);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        travel(root, result);
        return result;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        if(root ==NULL) return {};
        vector <int> res;
        stack <Node *> stk;

        // first push the eleement into the stack 
        stk.push(root);

        while(!stk.empty())
        {
            Node *temp = stk.top();
            res.push_back(temp->val);
            stk.pop();

            for(int i=temp->children.size()-1;i>=0;i--)
            {
                stk.push(temp->children[i]);
            }
        }

        //reverse(res.begin(),res.end());
        return res;
        
    }
};