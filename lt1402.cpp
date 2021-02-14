// https://leetcode-cn.com/problems/reducing-dishes/
// reducing dishes
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int sum = 0, ans = 0, size = satisfaction.size();
        for(int i = 0; i < size; i++){
            if(sum + satisfaction[i] > 0) {
                sum += satisfaction[i];
                ans += sum;
                continue;
            }
            break;
        }
        return ans;
    }
};