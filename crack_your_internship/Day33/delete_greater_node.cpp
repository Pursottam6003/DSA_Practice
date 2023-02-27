/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 Recursively call removeNodes to handle the tail first.
Then head.next node should have the biggest value.
Compare head.val and head.next.val,
if head.val < head.next.val,
should remove the current node,
return head.next,
otherwise we return head.
 */

// https://leetcode.com/problems/remove-nodes-from-linked-list/submissions/905472438/
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        
        ListNode *temp = head;
        
        if(!head) return NULL;

        head->next = removeNodes(head->next);

        return (head->next && head->val < head->next->val) ? head->next : head;
    }
};