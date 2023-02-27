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
// https://leetcode.com/problems/add-two-numbers-ii/description/
class Solution {
public:

    ListNode *reverseNode(ListNode *ptr)
    {
        ListNode *curr=ptr, *prev= NULL, *after;
        while(curr)
        {
            after = curr->next;
            curr->next = prev;

            prev= curr;
            curr = after;
        }

        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,sum=0;
        ListNode *dummy= new ListNode(0);
        ListNode *curr= dummy;

        l1= reverseNode(l1);
        l2 = reverseNode(l2);

        while(l1 || l2 || carry)
        {
            sum = 0; //initialsing our sum 
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
        return reverseNode(dummy->next);
    }
};