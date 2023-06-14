
// https://leetcode.com/problems/min-stack/submissions/970813934/
typedef long long int lli;
class MinStack {
public:

    lli miniEle;
    stack <lli> stk;
    MinStack() {
    }
    
    void push(int val) {
        val = (lli)val;

        if(stk.empty())
        {
            stk.push(val);
            miniEle = (lli)val;
        }
        else 
        {   
            if(val < miniEle)
            {   
              
                stk.push((lli)2*(val) - (lli)(miniEle));
                miniEle = val;
            }

            else 
            {   
                // update min elemenet with curr eleemnt
                stk.push(val);
            }
        }
    }
    
    void pop() {
        int top = stk.top();
        stk.pop();
       
        if(top < miniEle)
        {
            miniEle = (lli)2*miniEle -top;
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return miniEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



 class MinStack {

private: 
    stack <int> s1;
    stack <int> s2;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.empty() || val <= s2.top())
            s2.push(val);
    }
    
    void pop() {
        if(s1.top() == s2.top()) s2.pop();
        // s1 has to be get popped
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */