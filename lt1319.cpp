// https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/
// number of operations to make network connected
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int num = connections.size();
        
        if(num < n - 1)
            return -1;
        
        vector<int> ids(n, 0);
        vector<int> rank(n, 0);
        init(ids, n);
        for(int i = 0; i < num; i++){
            merge(ids, rank, connections[i][0], connections[i][1]);
        }
        
        int count = 0;
        for(int i = 0; i < n; i++){
            count += (ids[i] == i);
        }
        
        return count - 1;
    }
    
    int parent(vector<int>& ids, int n){
        return ids[n] == n ? n : parent(ids, ids[n]);
    }
    
    void init(vector<int>& ids, int n){
        for(int i = 0; i < n; i++)
            ids[i] = i;
    }
    
    void merge(vector<int>& ids, vector<int>& rank, int id1, int id2){
        int p1 = parent(ids, id1);
        int p2 = parent(ids, id2);
        if(p1 == p2)
            return;
        if(rank[p1] < rank[p2]){
            ids[p1] = p2;
        }else{
            if(rank[p1] == rank[p2])
                rank[p1]++;
            ids[p2] = p1;
        }
    }
    
    
};