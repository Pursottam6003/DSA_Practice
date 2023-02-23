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

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/submissions/903552922/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *trev=new ListNode (0,head);
        // predecessor = the last node
        // before the sublist of duplicates
        ListNode *pred = trev;

        while(head != NULL)
        {
            // if it is beginning of duplicates sublist 
            // skip all duplicates

            if(head->next != NULL && head->val == head->next->val)
            {
                // move till the end of duplicates sublist
                while(head->next != NULL && head->val == head->next->val)
                {
                    head= head->next;
                }

                // skip all duplicates
                pred->next = head->next;
            }
            else 
            {
                // otherwise move predecessor 
                pred = pred->next;
            }
            // move forward
            head=head->next;
        }

        return trev->next;
    }
};