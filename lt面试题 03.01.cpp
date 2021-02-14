// https://leetcode-cn.com/problems/three-in-one-lcci/
// three in one lcci
class TripleInOne {
public:
    TripleInOne(int stackSize) {
        eles.resize(stackSize * 3);
        pos.resize(3);
        this->stackSize = stackSize;
        for(int i = 0; i < 3; i++){
            pos[i] = stackSize * i;
        }
    }
    
    void push(int stackNum, int value) {
        if(pos[stackNum] == (stackNum + 1) * stackSize)
            return;
        eles[pos[stackNum]++] = value;
    }
    
    int pop(int stackNum) {
        if(pos[stackNum] == stackNum * stackSize)
            return -1;
        return eles[--pos[stackNum]];
    }
    
    int peek(int stackNum) {
        if(pos[stackNum] == stackNum * stackSize)
            return -1;
        return eles[pos[stackNum] - 1];
    }
    
    bool isEmpty(int stackNum) {
        return pos[stackNum] == stackNum * stackSize;
    }

    vector<int> eles;
    vector<int> pos;
    int stackSize;
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */