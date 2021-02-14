// https://leetcode-cn.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
// minimum number of increments on subarrays to form a target array
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        size_t size = target.size();
        vector<int> diff(size - 1, 0);
        int pos = 0;
        int neg = 0;
        for(int i = 0; i < size; i++){
            int diff = 0;
            if(i == 0){
                diff = target[i];
            }else{
                diff = target[i] - target[i - 1];
            }
            
            if(diff > 0){
                pos += diff;
            }else{
                neg += abs(diff);
            }
        }
        
        return max(pos, neg);
    }
};