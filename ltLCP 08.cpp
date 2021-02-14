// https://leetcode-cn.com/problems/ju-qing-hong-fa-shi-jian/
// ju qing hong fa shi jian
class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        size_t size = increase.size();
        vector<vector<int>> days = {3, vector<int>(size + 1, 0)};
        
        for(int i = 0; i < size; i++){
            days[0][i + 1] = days[0][i] + increase[i][0];
            days[1][i + 1] = days[1][i] + increase[i][1];
            days[2][i + 1] = days[2][i] + increase[i][2];
        }

        size = requirements.size();

        vector<int> res = {};

        for(int i = 0; i < size; i++){
            int start = search(days[0], requirements[i][0]);
            start = max(start, search(days[1], requirements[i][1]));
            start = max(start, search(days[2], requirements[i][2]));    
            if(start == days[0].size())
                start = -1;
            res.push_back(start);    
        }

        return res;
    }

    int search(vector<int>& arr, int target){
        int l = 0, r = arr.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            if(target < arr[mid]){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};