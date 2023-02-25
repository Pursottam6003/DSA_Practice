// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
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
 
    int pairSum(ListNode* head) {
        ListNode *fast=head, *slow = head;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // got the middle node as slow 

        // reverse the second half
        ListNode *prev=NULL, *curr=slow;
        ListNode *after=NULL;

        while(curr)
        {
            after = curr->next;
            curr->next = prev;
            // update the prev 
            prev = curr;
            curr = after; // swap
        }

        // reverses node will store in prev;
        int res=0;
        while(prev && head)
        {
            res = max(res,(prev->val+head->val));
            prev=prev->next;
            head=head->next;
        }
        return res;
    }

 
};