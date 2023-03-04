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
// https://leetcode.com/problems/insertion-sort-list/submissions/908842017/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

       ListNode *dummy = new ListNode(0); // new starter of the sorted list
       ListNode *curr = head; // the node will be inserted
       ListNode *prev=dummy; // insert node between pre and pre next
       ListNode *next = NULL; // the next node will be inserted 

       // not the end of input list
       while(curr != NULL)
       {
           next = curr->next;
           // find the right place to place 

           while(prev->next != NULL && prev->next->val < curr->val)
           {
               prev= prev->next;
           }
           // insrt between prev and prev->next

           curr->next = prev->next;
           prev->next = curr;
           prev = dummy;
           curr = next;
       }

        return dummy->next;
    }
};