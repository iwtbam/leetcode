// https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
// shu zu zhong de ni xu dui lcof
class BitTree {
public:
    BitTree(int n){
        this->n = n + 1;
        this->trees.resize(n + 1, 0);
    }
    
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

public:
    vector<int> trees;
    int n; 
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        size_t size = nums.size();
        BitTree bits(size);
        int ans = 0;
        for(int i = 0; i < size; i++){
            int index = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1;
            ans += i - bits.query(index);
            bits.add(index, 1);
        }
        return ans;
    }
};