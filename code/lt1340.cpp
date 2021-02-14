// https://leetcode-cn.com/problems/jump-game-v/
// jump game v
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        vector<pair<int, int>> arr_with_indexs = {};
        size_t size = arr.size();
        for(int i = 0; i < size; i++){
            arr_with_indexs.push_back({arr[i], i});
        }

        sort(arr_with_indexs.begin(), arr_with_indexs.end());
        int res = 1;
        vector<int> dp(size, 0);
        for(int i = 0; i < size; i++){
            int index = arr_with_indexs[i].second;
            dp[index] = 1;

            for(int left = index - 1; left >= index - d && left >=0; left--){
                if(arr[left] >= arr[index])
                    break;
                dp[index] = max(dp[index], dp[left] + 1);    
            }

            for(int right = index + 1; right <= index + d && right < size; right++){
                if(arr[right] >= arr[index])
                    break;
                dp[index] = max(dp[index], dp[right] + 1);
            }

            res = max(dp[index], res);
        }

        return res;
    }
};