// https://leetcode.com/problems/reverse-linked-list/
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
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
        
//         stack <int> stk;
        
//         while(head)
//         {   
//             if(head->val !=stk.top() || stk.empty())
//             {
//                 stk.push(head->val);
//             }
//             else 
//             {
//                 stk.pop();
//             }
//             head=head->next;
//         }
        
//         if(stk.size() <2) return true;
        
//         return false;
//     }
// };

class Solution {
public:
/*
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
    
    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
    */
    ListNode *temp; // global pointer
    bool isPalindrome(ListNode *head)
    {
        // assigning temp with head
        temp = head;
        return checkPallindrome(head);
    }

    bool checkPallindrome(ListNode *curr)
    {
        if(curr == NULL) return true;
        // recurssive call 
        bool isPal = checkPallindrome(curr->next) && curr->val == temp->val; 
        temp=temp->next;
        return isPal; 
    }
};