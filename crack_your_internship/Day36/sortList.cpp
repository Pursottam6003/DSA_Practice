/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        // creating dummy list for storing values
        // if list contain a single or 0 node

        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *temp=NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        // 2 pointer slow , fast approach 

        while(fast != NULL && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next; // by 1
            fast = fast->next->next; // by 2
        }

        temp->next = NULL;  // end of first left half

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

 

        return mergeList(l1,l2);
    }

    ListNode *mergeList(ListNode *l1,ListNode *l2)
    {
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;

        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }

            else 
            {
                curr -> next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        // for unequal  length linked list
        if(l1 != NULL)
        {
            curr-> next = l1;
            l1 = l1->next;
        }
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2->next;
        }
       
        return ptr->next;
    }

};