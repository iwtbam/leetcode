#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


class Solution {
public:
    
    struct cmp
    {
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
            if(p1.second == p2.second)
                return p1.first < p2.first;
            return p1.second > p2.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> record;
        for(auto num : nums)
            record[num]++;
        
        priority_queue<int, vector<pair<int, int>>, cmp> heap;
        
        size_t size = record.size();
        int i = 0;
        
        for(auto p: record){ 
            heap.push(p);
            if(i >= k)
                heap.pop();
            i++;
        }
        
        vector<int> res = {};
        
        while(!heap.empty()){
            res.push_back(heap.top().first);
            heap.pop();
        }
        
        return res;
    }
};