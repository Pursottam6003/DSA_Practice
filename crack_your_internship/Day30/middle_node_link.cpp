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
// https://leetcode.com/problems/middle-of-the-linked-list/description/
class Solution {
public:
    
    // approach 2
    
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast=head,*slow=head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next; //2 times 
        }
        return slow;
    }
    /*
    ListNode* middleNode(ListNode* head) {
        // we have to return the middle node 
        
        ListNode *temp = head;
        
        int ct=0;
        
        while(temp)
        {
            temp=temp->next;
            ct++;
        }
        
        ct=ct/2;
        while(ct--)
        {
            head=head->next;
        }
        
        return head;
    }
    */
};