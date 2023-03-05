// https://leetcode.com/problems/implement-queue-using-stacks/submissions/909332364/
class MyQueue {
public:
    stack <int> stk1;
    stack <int> stk2;

    /*
    While stack1 is not empty, push everything from stack1 to stack2.
Push x to stack1 (assuming size of stacks is unlimited).
Push everything back to stack1.
    */
    
    void push(int x) {
        // making push operation costly
        // pop all the elements of stack1 into stack 2

        while(! stk1.empty())
        {
            int val = stk1.top();
            stk2.push(val);
            stk1.pop();
        }
        stk1.push(x);

        while(! stk2.empty())
        {
            int val = stk2.top();
            stk1.push(val);
            stk2.pop();
        }
    }
    
    int pop() {
        int x = stk1.top();
        stk1.pop();
       return x;
    }
    
    int peek() {
        return stk1.top();
    }
    
    bool empty() {
        return stk1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */