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
// https://leetcode.com/problems/reverse-linked-list/submissions/904119029/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /*
        if(!head || !head->next )
        {
            return head;
        }

        else 
        {
            ListNode *new_head = reverseList(head->next);
            ListNode *new_tail = head->next;

            new_tail->next = head;
            head->next =NULL;
            return new_head;
        }
        */

        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *after;

        while(curr)
        {
            after =curr->next;
            curr->next=prev;
            
            prev = curr;

            curr = after;
        }

        return prev;



    }
};