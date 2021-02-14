// https://leetcode-cn.com/problems/arithmetic-subarrays/
// arithmetic subarrays
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> res(m, true);
        for(int i = 0; i < m; i++){
            int len = r[i] - l[i] + 1;
            if(len <= 2){
                res[i] = true;
                continue;
            }
            vector<int> array(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(array.begin(), array.end());
            for(int j = 0; j < len - 2; j++){
                if(array[j + 1] - array[j] != array[j + 2] - array[j + 1]){
                    res[i] = false;
                    break;
                }
            }
        }
        return res;
    }
};