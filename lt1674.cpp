// https://leetcode-cn.com/problems/minimum-moves-to-make-array-complementary/
// minimum moves to make array complementary
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int size = nums.size();
        vector<int> diff(limit * 2 + 2);
        for(int i = 0; i < size / 2; i++){
            int A = nums[i], B = nums[size - i - 1];
            diff[2] += 2;
            diff[limit * 2 + 1] -=2; 

            
            int L = 1 + min(A, B);
            int R = limit + max(A, B);

            diff[L] -= 1;
            diff[R + 1] += 1;
            
            diff[A + B] -= 1;
            diff[A + B + 1] += 1;
        }

        int ans = size, sum = 0;

        for(int i = 2; i <= 2 * limit; i++){
            sum += diff[i];
            ans = min(ans, sum);
        }
        return ans;
    }
};