#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(_s1.empty())
        {
           while(_s2.size())
           {
               _s1.push(_s2.top());
               _s2.pop();
           }
        }
        
        _s1.push(x);
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = peek();
        _s2.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if(_s2.empty())
        {
            while(_s1.size())
            {
                _s2.push(_s1.top());
                _s1.pop();
                    
            }
        }
        return _s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _s1.empty() && _s2.empty();
    }

private:
    stack<int> _s1;
    stack<int> _s2;
};
