// https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/
// shu ju liu zhong de zhong wei shu lcof
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(big.size() != small.size()){
            big.push(num);
            small.push(big.top());
            big.pop();
        }else{
            small.push(num);
            big.push(small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        if(big.size() == small.size())
            return (big.top() + small.top())/2.0;
        return big.top();
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