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
 // https://leetcode.com/problems/remove-linked-list-elements/description/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *temp=head;
        if(head==NULL) return head;
        while(temp && temp->next)
        {   
            if(temp->next->val == val)
            {
                temp->next = temp->next->next;
            }
            else 
            {    
                temp = temp->next;
            }
        }
        if(head->val == val) return head->next;
        return head;

    }
};