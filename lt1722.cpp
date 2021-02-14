// https://leetcode-cn.com/problems/minimize-hamming-distance-after-swap-operations/
// minimize hamming distance after swap operations
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        size_t n = source.size(), m = allowedSwaps.size();
        
        init(n);
        
        for(int i = 0; i < m; i++){
            merge(allowedSwaps[i][0], allowedSwaps[i][1]);
        }
        
        unordered_map<int, unordered_map<int, int>> record;
        
        for(int i = 0; i < n; i++){
           //cout << source[i] << " " << fa(i) << endl;
            record[fa(i)][source[i]]++;
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
           //cout << target[i] << " " << fa(i) << endl;
            int p = fa(i);
            if(record[p].count(target[i]) == 1 && record[p][target[i]] > 0){
                ans++;
                record[p][target[i]]--;
             //   cout << target[i] << endl;
            }
        }
       // cout << n << endl;
        return n - ans;
    }
    
    void init(int n){
        for(int i = 0; i < n; i++)
            nodes[i] = i;
    }
    
    int fa(int n){
        if(nodes[n] == n)
            return n;
        return nodes[n] = fa(nodes[n]);
    }
    
    void merge(int n1, int n2){
        nodes[fa(n1)] = nodes[fa(n2)];
        
    }
    
private:
    int nodes[100010];
};