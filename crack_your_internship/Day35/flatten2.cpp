/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/submissions/906458882/
class Solution {
public:
    Node* flatten(Node* head) {
        
        if(head == NULL) return head;

        Node *ptr = head;
        while(ptr != NULL)
        {
            // case 1 if there is no child proceed
            if(ptr->child == NULL)
            {
                ptr = ptr->next;
                continue;
            }

            // case 2 got child find the tail of child and link it to 
            Node *temp = ptr->child;

            // find the tail of the child go intil 

            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            // connect tail with p->next if it is not there 
            temp->next = ptr->next;

            if(ptr->next != NULL)
            {
                ptr->next->prev  = temp;
            }

            // connect ptr with ptr.child and remove p->child 

            ptr->next = ptr->child;
            ptr->child->prev =ptr;
            ptr->child = NULL;
        }
        return head;
    }
};