// https://leetcode-cn.com/problems/contiguous-array/
// contiguous array
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        size_t size = nums.size();
        int len = 0;
        unordered_map<int, int> record;
        record[0] = -1;
        int z = 0, o = 0;
        for(int i = 0; i < size; i++){
            z = z + 1 - nums[i];
            o = o + nums[i];
            // cout << z << " " << o << " " << record[z - o] << endl;
            if(record.count(z - o) == 1){
                len = max(i - record[z - o], len);
            }else{
                record[z - o] = i;
            }
        }
        return len;
    }
};