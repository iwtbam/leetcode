// https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
// bao han minhan shu de zhan lcof
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        eles.push(x);
        if(mins.size() && mins.top() < x)
            x = mins.top();
        mins.push(x);
    }
    
    void pop() {
        eles.pop();
        mins.pop();
    }
    
    int top() {
        return eles.top();
    }
    
    int min() {
        return mins.top();
    }

    stack<int> eles;
    stack<int> mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */