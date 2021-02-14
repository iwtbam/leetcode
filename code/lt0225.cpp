#include <queue>

using namespace std;

class MyStack {
public:
    MyStack() {
    }
    
    void push(int x) {
        if(_c1.empty())
        {
            _c1.push(x);
            while(_c2.size())
            {
                _c1.push(_c2.front());
                _c2.pop();
            
            }
        }
        else
        {
            _c2.push(x);
            while(_c1.size())
            {
                _c2.push(_c1.front());
                _c1.pop();
            }
        }
    }
    
    int pop() {
        int front = _c1.size() ? _c1.front() : _c2.front();
        _c1.size() ? _c1.pop() : _c2.pop();
        return front;
    }
    
    int top() {
        int front = _c1.size() ? _c1.front() : _c2.front();
        return front;
    }
    
    bool empty() {
        return _c1.empty() && _c2.empty();
    }

private:
    queue<int> _c1;
    queue<int> _c2;
};
