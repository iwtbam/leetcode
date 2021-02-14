// https://leetcode-cn.com/problems/graph-connectivity-with-threshold/
// graph connectivity with threshold
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        num = n;
        int m = queries.size();
        vector<bool> res(m, true);
        if(threshold < 1)
            return res;
        
        init();
        for(int i = threshold + 1; i <= n; i++){
            for(int j = 2; i * j <= n; j++){
                if(parent(j * i) != parent((j - 1) * i))
                    merge(j * i, (j - 1) * i);
            }
        }

        for(int i = 0; i < m; i++)
            res[i] = parent(queries[i][0]) == parent(queries[i][1]);
        return res;
    }
    
    void init(){
        for(int i = 1; i <= num; i++)
            nodes[i] = i;
    }
    
    int parent(int n){
        if(nodes[n] == n)
            return n;
        return nodes[n] = parent(nodes[n]);
    }
    
    void merge(int n1, int n2){
        nodes[parent(n1)] = nodes[parent(n2)];    
    }
    
private:
    int nodes[10001];
    int num;
};