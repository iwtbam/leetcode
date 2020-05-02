class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int x) {
        data_.push_back(x);
        if(min_.size() == 0){
            min_.push_back(x);
        }else{
            min_.push_back(min(x, min_.back()));
        }
    }
    
    void pop() {
        data_.pop_back();
        min_.pop_back();
    }
    
    int top() {
        return data_.back();
    }
    
    int getMin() {
        return min_.back();
    }

private:
    vector<int> data_ = {};
    vector<int> min_ = {};
    
};
