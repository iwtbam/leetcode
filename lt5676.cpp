// https://leetcode-cn.com/problems/minimum-changes-to-make-alternating-binary-string/
// minimum changes to make alternating binary string
class Solution {
public:
    int minOperations(string s) {
        int ans1 = 0, ans2 = 0;
        size_t n = s.size();
        for(int i = 0; i < n; i++){
            int num = s[i] - '0';
            ans1 += num == i % 2;
            ans2 += num == (i + 1) % 2;
        }
        
        return min(ans1, ans2);
    }
};