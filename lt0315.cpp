// https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/
// count of smaller numbers after self
class Solution {
public:
    int lowbit(int x){
        return x & (-x);
    }

    void add(int i, int val){
        while(i < n){
            trees[i] += val;
            i += lowbit(i);
        }
    }

    int query(int i){
        int sum = 0;
        while(i > 0){
            sum += trees[i];
            i -= lowbit(i);
        }
        return sum;
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        n = sorted.size() + 1;
        size_t size = nums.size();
        trees.resize(n, 0);
        vector<int> res(size, 0);
        int num = 0;
        for(int i = size - 1; i >= 0; i--){
            int index = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1;
            res[i] = query(index - 1);
            add(index, 1);
            num++;
        }
        return res;
    }

private:
    vector<int> trees;
    int n;
};