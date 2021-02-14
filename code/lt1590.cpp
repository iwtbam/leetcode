// https://leetcode-cn.com/problems/make-sum-divisible-by-p/
// make sum divisible by p
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> record;
        int size = nums.size();
        vector<int> mods(size + 1, 0);
        for(int i = 0; i < size; i++)
            mods[i + 1] = (mods[i] + nums[i]) % p;

        int last = mods[size];
        if(last == 0)
            return 0;
        int ans = size ;
        for(int i = 0; i <= size; i++){
            int mod = (mods[i] + p - last) % p;
            if(record.count(mod)){
                ans = min(ans, i - record[mod]);
            }
            record[mods[i]] = i;
        }

        return ans == size ? -1 : ans;
    }
};