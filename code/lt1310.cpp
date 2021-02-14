// https://leetcode-cn.com/problems/xor-queries-of-a-subarray/
// xor queries of a subarray
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = arr.size();
        int qsize = queries.size();
        vector<int> xors(size + 1, 0);
        for(int i = 0; i < size; i++){
            xors[i + 1] = arr[i] ^ xors[i];
        }
        
        vector<int> res(qsize, 0);
        for(int i = 0; i < qsize; i++){
            vector<int> query = queries[i];
            res[i] = xors[query[1] + 1] ^ xors[query[0]];
        }
        
        return res;
        
    }
};