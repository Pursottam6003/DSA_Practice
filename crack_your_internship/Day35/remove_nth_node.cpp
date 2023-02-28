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

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
class Solution {
public:
 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *fast  = head, *slow = head;

        for(int i=0;i<n;i++)
        {
            fast = fast->next;
        }

        if(!fast) return head->next; // end if size of linkest == n 

        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *t = slow->next;
        slow->next  = slow->next->next;
        delete t;
        return head;
    }
};