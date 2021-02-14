// https://leetcode-cn.com/problems/kth-missing-positive-number/
// kth missing positive number
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int max_val = *max_element(arr.begin(), arr.end());
        vector<int> record(max_val + k + 1, 0);
        size_t size = arr.size();
        for(int i = 0; i < size; i++)
            record[arr[i]] = 1;
        
        int num = 0;
        for(int i = 1; i <= max_val + k; i++){
            if(record[i] == 0){
                num++;
                if(num == k)
                    return i;
            }
        }
        
        return -1;
    }
};