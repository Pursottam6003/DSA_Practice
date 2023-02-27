// https://leetcode.com/problems/reverse-linked-list-ii/description/
class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int m, int n) {
 
    ListNode *dummy= new ListNode(0), *prev=dummy, *curr;
    dummy -> next = head;

    for(int i=0;i<m-1;i++)
    {
        prev =prev->next;
    }
    curr = prev->next;


    for(int i=0;i<n-m;i++)
    {   // swapping
        ListNode *t = prev->next;
        prev->next = curr->next;
        curr->next = curr->next->next;
        prev->next->next = t;
    }

    return dummy->next;

   }
};