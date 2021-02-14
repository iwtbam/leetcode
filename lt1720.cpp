// https://leetcode-cn.com/problems/decode-xored-array/
// decode xored array
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        size_t n = encoded.size();
        vector<int> res(n + 1, 0);
        res[0] = first;
        for(int i = 0; i < n; i++)
            res[i + 1] = res[i] ^ encoded[i];
        return res;
    }
};