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
// https://leetcode.com/problems/partition-list/submissions/906495923/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *preHead1 =  new ListNode(0);
        ListNode *preHead2 =  new ListNode(0);

        ListNode *h1= preHead1, *h2 = preHead2;

        while(head)
        {
            if(head->val <x)
            {
                h1->next = head;
                h1 = h1->next;
            }

            else 
            {
                h2->next  = head;
                h2 = h2->next;
            }
            head= head->next;
        }

        h1->next  = preHead2->next;
        h2->next = NULL;

        return preHead1->next;
        
        
    }
};