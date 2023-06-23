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

        ListNode *slow=head;
        ListNode *fast = head;

        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow= slow->next;
        }
        // get the middle of the element 
        ListNode *curr = slow;
        ListNode *prev = NULL;
        ListNode *after = NULL;
        while(curr)
        {
            after = curr->next;
            curr->next = prev;

            prev = curr;
            curr = after;
        }

        // reversed node will be stored inside prev  
        
        int res=0;
        

        while(prev && head)
        {
            res = max(res,prev->val+head->val);
            head= head->next;
            prev=prev->next;
        }

        return res;
    }
};