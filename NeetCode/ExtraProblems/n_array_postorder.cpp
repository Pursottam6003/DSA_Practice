/*

// https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
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

/*
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
       // check if the root node is null or what 

        if(root == NULL) return {}; // an empty vector 

        // create a stack to avoid recurssion technique 

        stack <Node *> stk;

        // push the root into the stackk

        vector <int> res;
        stk.push(root);

        while(!stk.empty())
        {   
            // recieve the top element of stack 
            Node * t = stk.top();
            stk.pop();


            for(int i=0;i<t->children.size();i++)
            {
                // store whoile node 
                stk.push(t->children[i]);
            }

            res.push_back(t->val);

            // pop that node after workk 
        }

        // reverse the vector to get actual answer 

        reverse(res.begin(),res.end());

        return res;
       
    }
};


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();

        vector <int> res;

        for(int i=0;i<n;i++)
        {
            while(res.size() && prices[res.back()] >= prices[i])
            {
                prices[res.back()] -= prices[i];
                res.pop_back();
            }
            res.push_back(i);
        }
        return prices;
    }
};



/*
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();
        vector <int> res(n,0);

        stack <int> stk;

    

        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() && stk.top() > prices[i])
            {   
                stk.pop();
            }

            if(stk.empty())
            {
                res[i] = prices[i];
            }

            else
            {
                res[i] = prices[i]- stk.top();
            }
            stk.push(prices[i]);

        }

        
        return res;
    }
};
*/