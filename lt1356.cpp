// https://leetcode-cn.com/problems/sort-integers-by-the-number-of-1-bits/
// sort integers by the number of 1 bits
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> buckets(32, vector<int>());
        size_t size = arr.size();
        for(int i = 0; i < size; i++){
            buckets[count(arr[i])].push_back(arr[i]);
        }

        size_t bucket_num = buckets.size();
        vector<int> res;

        for(int i = 0; i < bucket_num; i++){
            sort(buckets[i].begin(), buckets[i].end());
            res.insert(res.end(), buckets[i].begin(), buckets[i].end());
        }
        return res;
    }

    int count(int num){
        int n = 0;
        while(num != 0){
            num -= num & (-num);
            ++n;
        }
        return n;
    }
};
