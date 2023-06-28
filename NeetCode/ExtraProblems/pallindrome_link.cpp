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

    ListNode *temp;
    bool checkPallindrome(ListNode *head)
    {   
        if(head == NULL) return true;
        bool ispal = checkPallindrome(head->next) && temp->val == head->val;
        temp=temp->next;
        return ispal;
    }

    bool isPalindrome(ListNode* head) {

        // calling the function 
        temp = head;
        return checkPallindrome(head);
    }
};