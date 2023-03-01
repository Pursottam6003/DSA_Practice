// using min heap
class Solution {
public:
    struct compare
    {
        bool operator()(ListNode* a, ListNode *b)
        {
            return a->val > b->val;   // min heap  
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& arr) // saari linked list ka head arr mai hai
    {
        int j;
        for(j = 0;j< arr.size();j++){
            if(arr[j] != NULL)
                break;
        }
        if(j == arr.size()){ // all list empty
            return NULL;
        }
        
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;   
        for(int i = 0;i<arr.size();i++){
            if(arr[i] != NULL)
                pq.push(arr[i]);
        }
        
        ListNode *mergeH = new ListNode(0);
        ListNode *last = mergeH;
        while(!pq.empty())
        {
            ListNode* curr = pq.top();
            pq.pop();
            
            last->next = curr;
            last = last->next;
            
            if(curr != NULL && curr->next != NULL){
                pq.push(curr->next);
            }
            
        }
        return mergeH->next;
    }
};

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.empty()){
        return nullptr;
    }
    while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists.front();
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if(l1 == nullptr)
        {
            return l2;
        }

        if(l2 == nullptr)
        {
            return l1;
        }

        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }

        else 
        {
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};

// 
class Solution {
public:
    
    ListNode* mergeTwoSorted(ListNode *a, ListNode* b)
    {
        if(a==NULL) return b;
        if(b==NULL) return a;
        
        if(a->val<=b->val){
            a->next = mergeTwoSorted(a->next, b);
            return a;
        }
        else{
            b->next = mergeTwoSorted(a, b->next);
            return b;
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int n=lists.size();
        if(lists.size()==0) return NULL;
        while(n>1){
            
            for(int i=0;i<n/2;i++)
                lists[i] = mergeTwoSorted(lists[i], lists[n-i-1]);
            n = (n+1)/2;
        }
        return lists.front();
    }
};