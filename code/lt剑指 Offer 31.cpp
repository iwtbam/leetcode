// https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
// zhan de ya ru dan chu xu lie lcof
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        size_t size = pushed.size();
        reverse(popped.begin(), popped.end());
        stack<int> is;
        for(int i = 0; i < size; i++){
            is.push(pushed[i]);            
            while(is.size() && is.top() == popped.back()){
                popped.pop_back();
                is.pop();
            }
        }

        return popped.size() ==  0;
    }
};