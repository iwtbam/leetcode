// https://leetcode-cn.com/problems/optimize-water-distribution-in-a-village/
// optimize water distribution in a village
class UnionSet {
    public:
        UnionSet(int n){
            node.resize(n + 1);
            rank.resize(n + 1);

            for(int i = 1; i <= n; i++){
                node[i] = i;
            }
        }

        bool merge(int n1, int n2){
            int p1 = parent(n1);
            int p2 = parent(n2);
            if(p1 == p2)
                return false;
            
            if(rank[p1] < rank[p2]){
                node[p2] = node[p1];
            }else{
                node[p1] = node[p2];
                if(rank[p1] == rank[p2])
                    rank[p1]++; 
            }
            return true;
        }

        int parent(int n){
            return node[n] == n ? n : parent(node[n]);
        }

    private:
        vector<int> node;
        vector<int> rank;
};


class Solution {
public:

    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {

        for(int i = 1; i <= n; i++){
            pipes.push_back(vector<int>{0, i, wells[i - 1]});
        }

        auto cmp = [](const vector<int>& v1, const vector<int>& v2){
            return v1[2] < v2[2];
        };

        sort(pipes.begin(), pipes.end(), cmp);

        UnionSet us(n);

        int mst = 0;
        size_t size = pipes.size();

        for(int i = 0; i < size; i++){
            vector<int> pipe = pipes[i];
            if(!us.merge(pipe[0], pipe[1]))
                continue;
            mst += pipe[2];
        }

        return mst;
    }
};