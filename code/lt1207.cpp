// https://leetcode-cn.com/problems/unique-number-of-occurrences/
// unique number of occurrences
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> record(2001, 0);
        vector<int> r2(1001, 0);
        size_t size = arr.size();
        for(int i = 0; i < size; i++){
            record[arr[i] + 1000]++;
        }

        for(int i = 0; i < 2001; i++){
            int fre = record[i];
            if(fre == 0)
                continue;
            if(++r2[fre] > 1)
                return false;
        }
        return true;
    }
};