// https://leetcode-cn.com/problems/continuous-median-lcci/
// continuous median lcci
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
     
    }
    
    void addNum(int num) {
        if(big.size() == 0 || num <= big.top()){
            big.push(num);
        }else{
            small.push(num);
        }

        int diff = big.size() - small.size(); 
        while(diff > 1 || diff < 0){
            if(diff > 1){
                small.push(big.top());
                big.pop();
            }else{
                big.push(small.top());
                small.pop();
            }
            diff = big.size() - small.size();
        }
        return;
    }
    
    double findMedian() {
        if(big.size() == 0)
            return -1;
        if(small.size() == 0)
            return big.top();
        if(big.size() > small.size()){
            return big.top();
        }
        return (big.top() + small.top()) / 2.0;
    }

private:
    priority_queue<int, vector<int>, less<int>> big;
    priority_queue<int, vector<int>, greater<int>> small;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */