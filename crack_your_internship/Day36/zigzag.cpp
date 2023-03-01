//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *root)
{
	Node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
 

// } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

class Solution
{
    public:
    
    void swap(Node *a,Node *b)
    {
        int t = a->data;
        a->data = b->data;
        b->data = t;
    }
    
    Node *zigZag(Node* head)
    {
        Node *temp = head;
        bool bit = false;
        
        while(temp->next)
        {
            if(bit)
            {
                if(temp->data < temp->next->data)
                {
                    swap(temp,temp->next);
                }
                bit = false;
            }
            
            else 
            {
                if(temp->data > temp->next->data)
                {
                    swap(temp,temp->next);
                }
                bit = true;
            }
            temp  = temp->next;
        }
        
        return head;
         
    }
};

//{ Driver Code Starts.


int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Solution ob;
		Node *ans = ob.zigZag(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends