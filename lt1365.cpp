// https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number/
// how many numbers are smaller than the current number
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        size_t size = nums.size();
        vector<int> index(size, 0);
        vector<int> res(size, 0);

        iota(index.begin(), index.end(), 0);
        auto cmp = [&nums](const int e1, const int e2) {
            return nums[e1] < nums[e2];
        };

        sort(index.begin(), index.end(), cmp);

        int pre = 0;

        for(int i = 0; i < size; i++){
            if(i > 0 && nums[index[i]] != nums[index[i - 1]])
                pre = i;
                
            res[index[i]] = pre;
        }

        return res;
    }
};