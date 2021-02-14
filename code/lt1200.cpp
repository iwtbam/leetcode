// https://leetcode-cn.com/problems/minimum-absolute-difference/
// minimum absolute difference
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        int size = arr.size();
        vector<vector<int>> res = {};
        for(int i = 0; i < size - 1; i++){
            diff = min(diff, arr[i + 1] - arr[i]);
        }

        for(int i = 0; i < size - 1; i++){
            if(diff == arr[i + 1] - arr[i])
                res.push_back({arr[i], arr[i + 1]});
        }

        return res;
    }
};