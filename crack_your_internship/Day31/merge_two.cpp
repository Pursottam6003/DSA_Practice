// https://leetcode.com/problems/merge-two-sorted-lists/submissions/904092251/
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  {
		// if list1 happen to be NULL
		// we will simply return list2.
		if(l1 == NULL)
        {
			return l2;
		}
		
		// if list2 happen to be NULL
		// we will simply return list1.
		if(l2 == NULL)
        {
			return l1;
		} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
		if(l1 -> val <= l2 -> val)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		// we will call recursive l1 whole list and l2 -> next
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}
};	


// Iterative approach 

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        // if l1 become null return l2

        
        if(l1 ==NULL)
            return l2;
        // if lsit happend to be null
        // return list1
        if(l2 == NULL)
            return l1;
    
        // l1 is choosen
        
        ListNode *ptr = l1;
        if(l1-> val > l2->val)
        {
            ptr = l2;
            l2=l2->next;
        }
        else l1=l1->next;


        ListNode *curr=ptr; 
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                curr->next = l1;
                l1=l1->next;
            }
            else 
            {
                curr->next = l2;
                l2= l2->next;
            }
            curr= curr->next;
        }

        if(!l1)
        {
            curr->next = l2;
        }
        else 
        {
            curr->next = l1;
        }

        return ptr;
        
    }
};