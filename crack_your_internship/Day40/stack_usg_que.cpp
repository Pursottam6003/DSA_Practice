// https://leetcode.com/problems/implement-stack-using-queues/submissions/909419634/
class MyStack {
public:
    
    queue <int> que;

    void push(int x) {
        // by making the push operation costly 
        int size = que.size();
        que.push(x);
        while(size--)
        {   // changing the front to back making it lifo 
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int x  = que.front();
        que.pop();
        return x;
    }
    
    int top() {
        return que.front();
        
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */