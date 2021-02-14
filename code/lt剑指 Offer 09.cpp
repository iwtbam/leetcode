// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
// yong liang ge zhan shi xian dui lie lcof
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        int ret = -1;
        if(s2.size()){
            ret = s2.top();
            s2.pop();
        }

        if(ret == -1 && s1.size()){
            while(s1.size() > 1){
                s2.push(s1.top());
                s1.pop();
            }
            ret = s1.top();
            s1.pop();
        }
        return ret;
    }

    stack<int> s1;
    stack<int> s2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */