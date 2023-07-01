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
    /*
    ListNode *mergeList(ListNode *l1,ListNode *l2)
    {   
        ListNode *res=NULL;
        ListNode *trev = res;

        while(l1 != NULL && l2!=NULL)
        {   
            ListNode *newNode = new ListNode(0);
            if(l1->val > l2->val)
            {
                newNode->val = l1->val;
                // more the next pointer 
                l1 = l1->next;
                trev->next = newNode;
                trev = newNode;
            }

            else 
            {
                newNode->val = l2->val;
                l2 = l2->next;
                trev->next = newNode;
                trev = newNode;
            }
        }


        if(l1)
        {
            trev->next = l1;
        }

        if(l2)
        {
            trev->next = l2;
        }
        return res->next;
    }
    */
    ListNode *merge2List(ListNode *l1,ListNode *l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        /// check which is bigger 
        if(l2->val > l1->val) {
            l1->next = merge2List(l1->next,l2); 
            return l1;
        }
        else { 
            l2->next = merge2List(l1,l2->next); 
            return l2;
        }
        // return as dummy val
        return NULL;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *mergedHead = merge2List(list1,list2); 
        return mergedHead;
    }
};