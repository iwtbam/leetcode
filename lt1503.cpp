// https://leetcode-cn.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
// last moment before all ants fall out of a plank
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        int size = left.size();
        for(int i = 0; i < size; i++)
            res = max(res, left[i]);
        size = right.size();
        for(int i = 0; i < size; i++)
            res = max(res, n - right[i]);
        
        return res;
    }
};