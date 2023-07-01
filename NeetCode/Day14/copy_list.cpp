/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node *trev = head;
        // create a map to store all the elements 
        unordered_map <Node *,Node *> mpp;

        while(trev)
        {
            // store first node elements into map 
            // linked with existing map nodes as their key 

            mpp[trev] = new Node(trev->val);
            // traverse until 
            trev = trev->next;
        }

        // update trev 
        trev = head;

        while(trev)
        {
            // now check the into the map if it is present it wont create a duplicate 

            mpp[trev]->next = mpp[trev->next];
            mpp[trev]->random = mpp[trev->random];
            // traverse 
            trev = trev ->next;
        }

        // return the map having head 
        return mpp[head];
    }
};