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
// https://leetcode.com/problems/add-two-numbers/description/
class Solution {
public:
 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *dummy = new ListNode(0); // creating a dummy list
        ListNode *curr = dummy; // initialising an pointer

        int carry = 0; // initialising carry wuth 0

        // loop 
        while(l1 || l2 || carry)
        {
            int sum = 0; //initialsing our sum 
            if(l1 != NULL)
            {
                sum += l1->val;
                l1= l1->next;
            }

            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry= sum/10; 
            ListNode * node = new ListNode(sum%10);
            curr->next = node;
            curr = curr->next;
        }
        return dummy->next;

    }
};