// https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
// capacity to ship packages within d days
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 0;
        int r = accumulate(weights.begin(), weights.end(), 0);
        while(l < r){
            int mid = (l + r) >> 1;
            if(calc(weights, mid) <= D){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }

    int calc(const vector<int>& weights, int mw){
        int days = 0;
        size_t size = weights.size();
        int w = 0;
        for(int i = 0; i < size; i++){
            if(w < weights[i]){
                w = mw;
                days += 1; 
            }

            if(w < weights[i])
                return INT_MAX;
            w -= weights[i];
        }
        return days;
    }
};