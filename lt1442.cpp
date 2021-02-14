// https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
// count triplets that can form two arrays of equal xor
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int size = arr.size();
        int ans = 0;
        for(int i = 1; i < size; i++)
            ans += solve(arr, i);
        return ans;
    }
    
    int solve(vector<int>& arr, int index){
        unordered_map<long long, int> record;
        int size = arr.size();
        int ans = 0;

        long long res = 0;
        for(int i = index - 1; i >= 0; i--){
            res = res ^ arr[i];
            record[res]++;
        }
        
        res = 0;
        
        for(int i = index; i < size; i++){
            res = res ^ arr[i];
            if(record.count(res))
                ans = ans + record[res];
        }
        
        return ans;
    }
};