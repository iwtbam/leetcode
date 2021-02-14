// https://leetcode-cn.com/problems/reverse-pairs/
// reverse pairs
class Solution {
public:

    int lowbit(int x){
        return x & (-x);
    }

    void add(int i, int x){
        while(i < trees.size()){
            trees[i] += x;
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

    int search(long long target){
        int l = 0, r = sort_nums.size() - 1;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(sort_nums[mid] <= target){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        if(l == 0 && target < sort_nums[0])
            return 0;
        return l + 1;
    }

    int reversePairs(vector<int>& nums) {
        sort_nums = nums;
        sort(sort_nums.begin(), sort_nums.end());
        sort_nums.erase(unique(sort_nums.begin(), sort_nums.end()), sort_nums.end());
        trees.resize(sort_nums.size() + 1);
        size_t size = nums.size();
        int res = 0;
        for(int i = 0; i < size; i++){
            int index = search(nums[i] * 2LL);
            res += i - query(index);
            index = search(nums[i]);
            add(index, 1);
        }
        return res; 
    }

private:
    vector<int> trees;
    vector<int> sort_nums;
};
