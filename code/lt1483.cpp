// https://leetcode-cn.com/problems/kth-ancestor-of-a-tree-node/
// kth ancestor of a tree node
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        size_t size = static_cast<size_t>(n);
        int depth = ceil(log(n) / log(2));
        
        dp = {size, vector<int>(depth + 1, -1)};

        for(int i = 0; i < size; i++){
            dp[i][0] = parent[i];
        }

        for(int d = 1; d <= depth; d++){
            bool isContinue = false;
            for(int i = 0; i < size; i++){
                if(dp[i][d - 1] == -1 || dp[dp[i][d - 1]][d - 1] == -1)
                    continue;
               
                dp[i][d] = dp[dp[i][d - 1]][d - 1];
                isContinue = true;
            }
            if(!isContinue)
                break;
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        if(node == -1)
            return -1;

        if(k == 0)
            return node;
        
        int depth = floor(log(k) / log(2));
        if(depth >= dp[node].size())
            return -1;
        
        node = dp[node][depth];
        
        return getKthAncestor(node, k - pow(2, depth));
    }

private:
    vector<vector<int>> dp;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */