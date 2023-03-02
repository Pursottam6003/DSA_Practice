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
// https://leetcode.com/problems/reverse-nodes-in-k-group/
class Solution {
public:
    int getLen(ListNode *head)
    {   ListNode *temp=head;
        int ct=0;
        while(temp !=NULL)
        {
            ct++;
            temp=temp->next;
        }
        return ct;
    }
    ListNode* reverseKGroup(ListNode* head, int k,int len) {

        if(len < k) 
        {
            return head;
        }    

        int ct=0;

        ListNode *prev = NULL, *nex=NULL, *curr=head;

        while(ct <k && curr != NULL)
        {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            ct++;
        }

        if(nex != NULL)
        {   // linking with other link list recursively 
            head ->next = reverseKGroup(nex,k,len-k);
        }
        return prev;
    }

    ListNode *reverseKGroup(ListNode *head,int k)
    {
        int len = getLen(head);
        return reverseKGroup(head,k,len);
    }
};