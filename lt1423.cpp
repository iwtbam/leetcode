// https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
// maximum points you can obtain from cards
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int size = cardPoints.size();
        for(int i = 0; i < k; i++){
            sum += cardPoints[i];
        }

        int res = sum;
        for(int i = 0; i < k; i++){
            sum = sum - cardPoints[k - i - 1] + cardPoints[size - i - 1];
            res = max(res, sum);
        }

        return res;
    }
};