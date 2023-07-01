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
        
        ListNode *dummy= new ListNode(0);
        ListNode *trev=dummy;

        int carry=0 ,sum=0;
        while(l1 && l2 || carry)
        {
            sum =0;
            // create a newNode 
            ListNode *newNode = new  ListNode(0); 
            if(l1)
            {
                sum += l1->val;  
                l1 = l1->next;           
            }

            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum = sum+carry;
            newNode->val = (sum%10);
            carry = sum /10;
            trev->next = newNode;
            trev = newNode;
        }

        while(l1)
        {
            ListNode *newNode = new  ListNode(0); 
            newNode ->val = l1->val;
            l1 = l1->next;

            trev->next = newNode;
            trev = newNode;
        }


        while(l2)
        {
            ListNode *newNode = new  ListNode(0); 
            newNode ->val = l2->val;
            l2 = l2->next;

            trev->next = newNode;
            trev = newNode;
        }

        return dummy->next;
    }
};