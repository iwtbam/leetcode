// https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
// shu zu zhong shu zi chu xian de ci shu ii lcof
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            count[nums[i]]++;
        }

        for(int i = 0; i < size; i++){
            if(count[nums[i]] == 1)
                return nums[i];
        }

        return 0;
    }
};