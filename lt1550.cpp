// https://leetcode-cn.com/problems/three-consecutive-odds/
// three consecutive odds
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int even = 0;
        size_t size = arr.size();
        for(int i = 0; i < size; i++){
            if(arr[i] & 1) even++;
            else even = 0;
    
            if(even == 3)
                return true;
        }

        return false;
    }
};