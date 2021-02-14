// https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets/
// minimum number of days to make m bouquets
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int day = *max_element(bloomDay.begin(), bloomDay.end());
        int l = 1, r = day + 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            int num = flowers(bloomDay, mid, k);
            //cout << mid << " " << num << endl;
            if(num < m){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l == day + 1 ? -1 : l;
    }
    
    int flowers(vector<int>& bloomDay, int d, int k){
        
        int len = 0, res = 0,size = bloomDay.size();
        for(int i = 0; i < size; i++){
            if(d >= bloomDay[i]){
                len += 1;
            }else{
                res += len / k;
                len = 0;
            }
        }
        
        res += len / k;
        return res;
    }
};