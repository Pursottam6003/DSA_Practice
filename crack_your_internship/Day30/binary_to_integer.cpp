// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/
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
    int getDecimalValue(ListNode* head) {
        
        int res=0,ct=0;

        ListNode *temp=head;
        while(temp)
        {
            temp=temp->next;
            ct++;
        }
        ct--;

        while(head)
        {
            int data = head->val;
            res += data*pow(2,ct);
            ct--;
            head=head->next;
        }
        return res;
    }

    
    int getDecimalValue (ListNode *head)
    {
        int res =0;
        while(head)
        {
            res = res*2 + head->val; // multiply by 2
            //res += head->val;
            head=head->next;
        }
        return res;
    }
};