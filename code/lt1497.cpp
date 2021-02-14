// https://leetcode-cn.com/problems/check-if-array-pairs-are-divisible-by-k/
// check if array pairs are divisible by k
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        size_t size = arr.size();
        unordered_map<int, int> record;
        for(int i = 0; i < size; i++){
            record[(arr[i] % k + k) % k]++;
        }
        
        for(int i = 1; i < k; i++){
            if(record[i] != record[k - i])
                return false;
        }
        
        return record[0] % 2 == 0;
    }
};