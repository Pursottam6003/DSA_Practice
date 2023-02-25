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
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/submissions/904503637/
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode *fast=head;
        ListNode *slow = head;
        ListNode *prev;
        // traverse to the middle of the link list 

        if(head->next == NULL) return NULL;

        while(fast && fast->next)
        {   prev= slow;
            slow = slow->next; // one tim2
            fast = fast->next->next; // 2 times
        }

        // no we have the slow 
        ListNode *temp=slow;
 
        prev->next = slow->next;

        return head;
    }
};