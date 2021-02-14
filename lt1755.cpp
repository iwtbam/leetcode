// https://leetcode-cn.com/problems/closest-subsequence-sum/
// closest subsequence sum
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int half = n /2;
        int t1 = 1 << half, t2 = 1 << (n - half);
        
        vector<int> sums1(t1, 0), sums2(t2, 0);
        
        for(int i = 0; i < t1; i++){
            for(int j = 0; j < half; j++)
                if(i >> j & 1)
                    sums1[i] += nums[j];
        }

        sort(sums1.begin(), sums1.end());
        int ans = INT_MAX;
        
        for(int i = 0; i < t2; i++){
            int num = 0;
            for(int j = 0; j < n - half; j++){
                if(!(i >> j & 1))
                    continue;
                num += nums[half + j];
            }

            int diff = goal - num;
            int l = lower(sums1, diff);
            ans = min(ans, abs(sums1[l] + num - goal));
            if(l > 0)
                ans = min(ans, abs(sums1[l - 1] + num - goal));
        }           

        return ans;
    }
    
    
    int lower(const vector<int>& sums, int target){
        int l = 0, r = sums.size() - 1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(sums[mid] >= target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return l;
    }
};