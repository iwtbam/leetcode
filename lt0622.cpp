#include <vector>

using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        _con = vector<int>(k + 1, 0);
        size = k + 1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())
            return false;
        _con[pE] = value;
        pE = (pE + 1) % size;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
            return false;
        pB = (pB + 1) % size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
            return -1;
        return _con[pB];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())
            return -1;
        
        int tail = pE - 1 == -1 ? size - 1 : pE - 1;
            
        return _con[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return pB == pE;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (pE + 1) % size == pB;
    }

private:
    vector<int> _con = {};
    int pB = 0, pE = 0;
    int size;
};