// https://leetcode-cn.com/problems/least-number-of-unique-integers-after-k-removals/
// least number of unique integers after k removals
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> record = {};
        size_t size = arr.size();
        for(int i = 0; i < size; i++){
            record[arr[i]]++;
        }
        
        vector<pair<int, int>> sorted = {record.begin(), record.end()};
        sort(sorted.begin(), sorted.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second < p2.second;
        });
        
        size = sorted.size();
        
        int remove = 0;
        
        for(int i = 0; i < size; i++){
            if(k < sorted[i].second){
                break;
            }
            remove++;
            k -= sorted[i].second;
        }
        
        return size - remove;
        
    }
};