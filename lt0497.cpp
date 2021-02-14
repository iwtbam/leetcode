// https://leetcode-cn.com/problems/random-point-in-non-overlapping-rectangles/
// random point in non overlapping rectangles
class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        size = rects.size();
        sums.resize(size + 1, 0);

        for(int i = 0; i < size; i++)
            sums[i + 1] = sums[i] + (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);

        srand((unsigned)time(nullptr));
    }
    
    vector<int> pick() {
        int num = rand() % sums[size] + 1;
        int pos = lower_bound(sums.begin(), sums.end(), num) - sums.begin();
        num = num - sums[pos - 1];
        pos = pos - 1;

        vector<int> cans(2, 0);
        cans[0] = rects[pos][0] + (num - 1) % (rects[pos][2] - rects[pos][0] + 1);
        cans[1] = rects[pos][1] + (num - 1) / (rects[pos][2] - rects[pos][0] + 1);

        return cans;
    }

private:
    vector<int> sums;
    vector<vector<int>> rects;
    size_t size;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */