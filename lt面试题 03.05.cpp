// https://leetcode-cn.com/problems/sort-of-stacks-lcci/
// sort of stacks lcci
class SortedStack {
public:
    SortedStack() {

    }
    
    void push(int val) {
        while(s1.size() && val > s1.top()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(val);

        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    void pop() {
        if(isEmpty())
            return;
        s1.pop();
    }
    
    int peek() {
        if(isEmpty())
            return -1;
        return s1.top();
    }
    
    bool isEmpty() {
        return s1.empty();
    }

    stack<int> s1;
    stack<int> s2;
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */