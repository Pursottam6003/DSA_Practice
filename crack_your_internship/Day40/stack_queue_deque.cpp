/*
In general, we can define Deque as below:

Deque<Integer> stack = new ArrayDeque<>();
When a deque is used as a queue, FIFO (First-In-First-Out) behavior results. Elements are added at the end of the deque and removed from the beginning. The methods inherited from the Queue interface are precisely equivalent to Deque methods as indicated below:

Queue Method -> Equivalent Deque Method
add(e) -> addLast(e)
offer(e) -> offerLast(e)
remove() -> removeFirst()
poll() -> pollFirst()
element() -> getFirst()
peek() -> peekFirst()

Deques can also be used as LIFO (Last-In-First-Out) stacks. This interface should be used in preference to the legacy Stack class. When a deque is used as a stack, elements are pushed and popped from the beginning of the deque. Stack methods are precisely equivalent to Deque methods as indicated in the table below:

Stack Method -> Equivalent Deque Method
push(e) -> addFirst(e)
pop() -> removeFirst()
peek() -> peekFirst()
*/


// c++ program to implement stack and queue uising deque 

#include <bits/stdc++.h>
using namespace std;

// structure for a node of deque 
struct DQueNode{
    int val;
    DQueNode *next;
    DQueNode *prev;
};

// implementation of deque class
class Deque {

private:

    // pointer to head and tail of deque 
    DQueNode *head;
    DQueNode *tail;

public: 
    // constructor 
    Deque ()
    {
        head = tail = NULL;
    }

    // if list is empty 
    bool isEmpty()
    {
        if(head == NULL)
            return true;
        return false;
    }

    // count the no of nodes in list
    int size()
    {
        // if list is not empty 
        if(!isEmpty())
        {
            DQueNode *temp = head;
            int len =0;

            while(temp != NULL)
            {
                len++;
                temp = temp->next;
            }
            return len;
        }
        return 0;
    }

    // insert at the first position 

    void insert_first(int element)
    {
        // allocating node of DQueNode type
        // creating new node
        DQueNode *newNode = new DQueNode[sizeof(DQueNode)];

        newNode->val = element;
        
        if(head ==NULL)
        {
            head = tail = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
        }

        else 
        {
            head->prev = newNode;
            newNode->next = head;
            newNode->prev = NULL;
            // making the new head 
            head = newNode;
        }
    }

    // insert at last position of deque 
    void insert_last(int element)
    {
        // allocating node of deque type 
        DQueNode *newNode = new DQueNode[sizeof(DQueNode)];
        newNode->val = element;

        // if the element is first element 
        if(head == NULL)
        {
            head = tail = newNode;
            newNode->next = newNode->prev = NULL;
        }

        else 
        {
            tail->next = newNode;
            newNode->prev= tail;
            newNode->next = NULL;
            tail = newNode; // updating tail 
            // either you can use tail = tail->next 
        }
    }

    // remove element from first position 
    void remove_first()
    {
        // if the list is not empty 

        if(!isEmpty())
        {
            DQueNode *temp = head;
            head = head->next; // updating head 

            if(head )
            {
                // if head exists ie not null
                head->prev  = NULL;
                delete temp;
            }

            else if(head == NULL) tail = NULL;
            return;
        }

        else 
            cout<<"List is empty"<<endl;
    }

    void remove_last()
    {
        if(!isEmpty())
        {
            DQueNode *temp = tail;
            tail = tail->prev;
            // one step back
            if(tail) tail ->next = NULL;

            delete temp;
            if(tail == NULL) head = NULL;
            return;
        }

        else cout<<"List is empty"<<endl;
    }

    // display the element in deque 
    void display()
    {
        // if list is not empty
        // if list is not empty
        if (!isEmpty()) {
            DQueNode* temp = head;
            while (temp != NULL) {
                cout << temp->val<< " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
        cout << "List is Empty" << endl;

    }
};

// Class to implement stack using Deque
class Stack : public Deque {
public:
    // push to push element at top of stack
    // using insert at last function of deque
    void push(int element)
    {
        insert_last(element);
    }
 
    // pop to remove element at top of stack
    // using remove at last function of deque
    void pop()
    {
        remove_last();
    }
};
 
// class to implement queue using deque
class Queue : public Deque {
public:
    // enqueue to insert element at last
    // using insert at last function of deque
    void enqueue(int element)
    {
        insert_last(element);
    }
 
    // dequeue to remove element from first
    // using remove at first function of deque
    void dequeue()
    {
        remove_first();
    }
};
 
// Driver Code
int main()
{
    // object of Stack
    Stack stk;
 
    // push 7 and 8 at top of stack
    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();
 
    // pop an element
    stk.pop();
    cout << "Stack: ";
    stk.display();
 
    // object of Queue
    Queue que;
 
    // insert 12 and 13 in queue
    que.enqueue(12);
    que.enqueue(13);
    cout << "Queue: ";
    que.display();
 
    // delete an element from queue
    que.dequeue();
    cout << "Queue: ";
    que.display();
 
    cout << "Size of Stack is " << stk.size() << endl;
    cout << "Size of Queue is " << que.size() << endl;
    return 0;
}