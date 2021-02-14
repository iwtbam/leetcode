// https://leetcode-cn.com/problems/build-an-array-with-stack-operations/
// build an array with stack operations
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops = {};
        size_t size = target.size();
        int cur = 1;
        
        for(int i = 0; i < size; i++){

            while(cur < target[i]){
                ops.push_back("Push");
                ops.push_back("Pop");
                cur = cur + 1;
            }
            
            ops.push_back("Push");
            cur = cur + 1;
        }
        
        return ops;
    }
};