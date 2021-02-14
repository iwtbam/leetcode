// https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/
// gou jian cheng ji shu zu lcof
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        for(int i = 1; i < n; i++)
            left[i] = left[i - 1] * a[i - 1];
        
        for(int i = n - 2; i >= 0; i--)
            right[i] = right[i + 1] * a[i + 1];

        for(int i = 0; i < n; i++){
            left[i] = left[i] * right[i];
        }
        return left;
    }
};