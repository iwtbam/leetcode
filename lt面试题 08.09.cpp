// https://leetcode-cn.com/problems/bracket-lcci/
// bracket lcci
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 1){
            return {"()"};
        }

        unordered_set<string> res = {};
        for(int i = 1; i <= n / 2; i++){
            vector<string> left = generateParenthesis(i);
            vector<string> right = generateParenthesis(n - i);
            size_t s1 = left.size();
            size_t s2 = right.size();
            for(int j = 0; j < s1; j++){
                for(int k = 0; k < s2; k++){
                    res.insert(left[j] + right[k]);
                    res.insert(right[k] + left[j]);
                }
            }
        }

        vector<string> inner = generateParenthesis(n - 1);

        size_t s = inner.size();
        for(int i = 0; i < s; i++){
            res.insert("(" + inner[i] + ")");
        }

        return {res.begin(), res.end()};
    }
};