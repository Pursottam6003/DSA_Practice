//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    /*
    Node* segregate(Node *head) {
        
        Node *temp = head;
        
        int zero=0,one=0,two=0;
        
        while(temp)
        {
            if(temp->data ==0)
            {
                zero++;
            }
            else if(temp->data ==1) one++;
            else two++;
            temp=temp->next;
        }
        
        temp = head;
        
        while(temp !=NULL)
        {
            if(zero >0)
            {   zero--;
                temp->data=0;
            }
            else if(one >0)
            {   one--;
                temp->data=1;
            }
            
            else
            {   two--;
                temp->data=2;
            }
            temp=temp->next;
            
        }
        return head;
        
    }
    */
    
    void insertAtTail(Node * &tail,Node *curr)
    {
        tail->next = curr;
        tail = curr;
    }
    
    Node *segregate(Node *head)
    {
        Node *zeroHead = new Node(-1);
        Node *zeroTail = zeroHead;
        Node *oneHead = new Node(-1);
        Node *oneTail = oneHead;
        Node *twoHead = new Node(-1);
        Node *twoTail = twoHead;
        
        
        Node *curr = head;
        
        // create a sepearte list 0s,1s and 2s
        
        while(curr != NULL)
        {
            int val = curr->data;
            
            if(val ==0)
            {
                insertAtTail(zeroTail,curr);
            }
            
            else if(val==1)
            {
                insertAtTail(oneTail,curr);
            }
            else if(val==2)
            {
                insertAtTail(twoTail,curr);
            }
            curr = curr->next;
        }
        
        // merge 3 sublist 
        // 1s list is not empty
        if(oneHead->next != NULL)
        {
            zeroTail->next = oneHead->next;
        }
        
        else 
        {
            // 1s is empty
            zeroTail->next = twoHead->next;
        }
        
        
        oneTail -> next = twoHead->next;
        twoTail->next = NULL;
        
        
        // uodating head
        head = zeroHead->next;
        
        // delte dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends