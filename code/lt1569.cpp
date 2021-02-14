// https://leetcode-cn.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
// number of ways to reorder array to get same bst
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        memset(C, 0, sizeof(C));
        size_t size = nums.size();

        for(int j = 0; j <= size; j++){
            C[j][j] = 1;
            for(int i = j + 1; i <= size; i++){
                if(j == 0)
                    C[i][j] = 1;
                else
                    C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
            }
        }

        

        //return 0;
        return calc(nums) - 1;
    }

    int calc(const vector<int>& nums){
        if(nums.size() <= 1)
            return 1;
        
        int pivot = nums[0];
        int size = nums.size();
        vector<int> left;
        vector<int> right;

        for(int i = 1; i < size; i++){
            if(nums[i] > nums[0]){
                left.push_back(nums[i]);
            }else{
                right.push_back(nums[i]);
            }
        }
        int l = left.size();
        int r = right.size();
        return ((C[l + r][r] * calc(left) % mod) * calc(right)) % mod;
    }

private:
    long long mod = 1e9 + 7;
    long long C[1002][1002];
};