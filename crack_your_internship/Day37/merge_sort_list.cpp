//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    
    Node *mergeList(Node *l1, Node *l2)
    {   
        Node *myhead = new Node(0);
        Node *trev = myhead; 
    
        
        
        while(l1 && l2)
        {
            if(l1->data > l2->data)
            {
                trev->next = l2;
                l2 =l2->next;
            }
            
            else 
            {
                trev->next = l1;
                l1= l1->next;
            }
            
            trev = trev->next;
        }
        
        if(l1) trev->next = l1;
        else if(l2 ) trev->next =l2;
        
        return myhead->next;
    }
    
    Node* mergeSort(Node* head) {
        
        if(head ==NULL || head->next ==NULL) return head;
        Node *p1 = head;
        Node *p2 = head;
        Node *temp = head;
        
        while(p2!=NULL  && p2->next!=NULL )
        {   
            temp = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        

        temp->next = NULL;
        
        Node *l1  = mergeSort(head);
        Node *l2 = mergeSort(p1);
        return mergeList(l1,l2);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends