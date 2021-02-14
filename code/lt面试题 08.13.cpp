// https://leetcode-cn.com/problems/pile-box-lcci/
// pile box lcci
class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        sort(box.begin(), box.end(), less<vector<int>>());
        size_t size = box.size();
        vector<int> dp(size, 0);
        for(int i = 0; i < size; i++)
            dp[i] = box[i][2];


        auto cmp = [](const vector<int>& v1, const vector<int>& v2)-> bool {
            return v1[0] < v2[0] && v1[1] < v2[1] && v1[2] < v2[2];
        };

        int h = dp[0];

        for(int i = 1; i < size; i++){
            for(int j = i - 1; j >= 0; j--){
                if(cmp(box[j], box[i])){
                    dp[i] = max(dp[i], dp[j] + box[i][2]);
                }
            }
            h = max(h, dp[i]);
        }        

        return h;
    }
};