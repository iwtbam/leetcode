// https://leetcode-cn.com/problems/maximum-score-after-splitting-a-string/
// maximum score after splitting a string
class Solution {
public:
    int maxScore(string s) {
        size_t size = s.size();
        
        vector<int> left(size, 0);
        vector<int> right(size, 0);
        
        left[0] = s[0] == '0' ? 1 : 0;

        for(int i = 1; i < size; i++){
            if(s[i] == '0')
                left[i] = left[i - 1] + 1;
            else
                left[i] = left[i - 1];
        }

        right[size - 1] = s[size - 1] - '0';
        for(int i = size - 2; i >= 0; i--){
            right[i] = s[i] - '0' + right[i + 1];
        }

        int res = 0;
        for(int i = 0; i < size - 1; i++){
            res = max(res, left[i] + right[i + 1]);
        }

        return res;
    }
};