// https://leetcode-cn.com/problems/find-kth-largest-xor-coordinate-value/
// find kth largest xor coordinate value
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<long long>> xors(rows + 1, vector<long long>(cols + 1, 0));
        
        priority_queue<long long, vector<long long>, greater<long long>> q;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                xors[i + 1][j + 1] = xors[i + 1][j] ^ xors[i][j + 1] ^ xors[i][j] ^ matrix[i][j];
                if(q.size() < k){
                    q.push(xors[i + 1][j + 1]);
                }else{
                    if(xors[i + 1][j + 1] > q.top()){
                        q.pop();
                        q.push(xors[i + 1][j + 1]);
                    }
                }
            }
        }
        
        return q.top();
    }
};