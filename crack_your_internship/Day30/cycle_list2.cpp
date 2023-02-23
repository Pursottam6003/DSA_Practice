/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
// https://leetcode.com/problems/linked-list-cycle-ii/description/
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head,*slow=head,*entry=head;

        while(fast && fast->next)
        {
            slow=slow->next;
            fast = fast->next->next;
            if(slow == fast) 
            {
                while(slow !=entry)
                {
                    slow=slow->next;
                    entry=entry->next;
                }   
                return entry;
            }
                

        }
        return NULL;
    }
};