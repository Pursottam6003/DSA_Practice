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

 // https://leetcode.com/problems/reverse-nodes-in-k-group/description/
class Solution {
public:

    int getLen(ListNode *head)
    {
        ListNode *ptr= head;
        int len=0;
        while(ptr)
        {
            ptr = ptr->next;
            len++;
        }

        return len;
    }

    ListNode *reverseGroup(ListNode *head,int k,int l)
    {
        // check if len is len then k then simopley return head;

        if(l < k) return head;

        // create pointers for storing prev and curr head 

        ListNode *curr = head, *prev = NULL, *after=NULL;
        int ct=0;
        while(ct <k && curr!=NULL)
        {
            after = curr->next;
            curr->next = prev;

            prev = curr;    
            curr = after;
            ct++;
        }

        // if the last pointer ie after is not null it does not reched end 
        // return 

        
        if(after != NULL) 
        {
            head ->next = reverseGroup(after,k,l-k);
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int l = getLen(head);
        // calling the function 
        return reverseGroup(head,k,l);
    }
};