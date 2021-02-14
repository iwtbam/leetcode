// https://leetcode-cn.com/problems/can-make-arithmetic-progression-from-sequence/
// can make arithmetic progression from sequence
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size() == 2)
            return true;
        sort(arr.begin(), arr.end());
        int size = arr.size();
        for(int i = 0; i < size - 2; i++){
            if(arr[i] - arr[i + 1] != arr[i + 1] - arr[i + 2])
                return false;
        }
        return true;
    }
};