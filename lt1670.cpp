// https://leetcode-cn.com/problems/design-front-middle-back-queue/
// design front middle back queue
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {

    }
    
    void pushFront(int val) {
        front.push_front(val);
        adjust();
    }
    
    void pushMiddle(int val) {
        front.push_back(val);
        adjust();
    }
    
    void pushBack(int val) {
        back.push_back(val);
        adjust();
    }
    
    int popFront() {
        int val = -1;
        if(front.size() == 0){
            if(back.size() == 0)
                return -1;
            val =  back.front();
            back.pop_front();
        }else{
            val = front.front();
            front.pop_front();
        }
        adjust();
        return val;
    }
    
    int popMiddle() {
        if(front.size() == 0 && back.size() == 0)
            return -1;
        int val = -1;
        if(back.size() > front.size()){
            val = back.front();
            back.pop_front();
        }else{
            val = front.back();
            front.pop_back();
        }
        adjust();
        return val;
    }
    
    int popBack() {
        int val = -1;
        if(back.size() == 0){
            if(front.size() == 0)
                return -1;
            else{
                val = front.back();
                front.pop_back();
            }
        }else{
            val = back.back();
            back.pop_back();
        }
        adjust();
        return val;
    }
    
    void adjust() {
        while(front.size() > back.size()){
            back.push_front(front.back());
            front.pop_back();
        }
        
        while(back.size() > front.size() + 1){
            front.push_back(back.front());
            back.pop_front();
        }
    }
    
private:
    deque<int> front, back;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */