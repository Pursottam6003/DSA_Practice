//{ Driver Code Starts
//Initial template for C++
// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

8 15 17 9 2 4 6
8 2  17 9 15 4 6


*/
class Solution{

public:
    
    void swap(Node *a,Node *b)
    {
        int t = a->data;
        a->data = b->data;
        b->data = t;
    }

    Node* divide(int N, Node *head){
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        // code here
        Node *odd =  new Node(-1);
        Node *even = new Node(-1);
        Node *temp=head;
        
        Node *oddptr = odd;
        Node *evenptr = even;
        
        while(temp)
        {
            if(temp->data %2 ==0)
            {
                evenptr->next = temp;
                evenptr=evenptr->next; //uupdate the pointer
            }
            
            else 
            {
                oddptr->next = temp;
                oddptr = oddptr->next;
            }
            temp = temp->next;
        }
        
        if(even->next !=NULL)
        {
            evenptr->next = odd->next;
            oddptr->next = NULL;
            return even->next;
        }
        head = odd->next;
        delete odd;
        delete even;
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends