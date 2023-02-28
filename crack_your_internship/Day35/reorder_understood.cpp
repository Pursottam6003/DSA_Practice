/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 1  2  3  4

How its made 
1  4  2  3



*/
/*
class Solution {
public:
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return; // Edge cases
        
        stack<ListNode*> my_stack;
        ListNode* ptr = head;
        int size = 0;
        while (ptr != NULL) // Put all nodes in stack
        {
            my_stack.push(ptr);
            size++;
            ptr = ptr->next;
        }
        
        ListNode* pptr = head;
        for (int j=0; j<size/2; j++) // Between every two nodes insert the one in the top of the stack
        {
            ListNode *element = my_stack.top();
            my_stack.pop();
            element->next = pptr->next;
            pptr->next = element;
            pptr = pptr->next->next;
        }
        pptr->next = NULL;
    }
};

*/

//Upvote and Comment
class Solution {
public:
    void reorderList(ListNode* head) {
        // base case : linkedlist is empty
        if (!head) return;
        
        // finding the middle with the help of two pointer approach
        ListNode *tmp = head, *half = head, *prev = NULL;
        while (tmp->next && tmp->next->next) {
            tmp = tmp->next->next;
            half = half->next;
        }
        
        // adding one bit in case of lists with even length
        if (tmp->next) half = half->next;
        
        // Now reverse the second half
        while (half) {
            tmp = half->next;
            half->next = prev;
            prev = half;
            half = tmp;
        }
        half = prev;
        
        // After reversing the second half, let's merge both the halfes
        while (head && half) {
            tmp = head->next;
            prev = half->next;
            head->next = half;
            half->next = tmp;
            head = tmp;
            half = prev;
        }
        
        // Base case : closing when we had even length arrays
        if (head && head->next) head->next->next = NULL;
    }
};
