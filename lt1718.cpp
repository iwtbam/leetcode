// https://leetcode-cn.com/problems/construct-the-lexicographically-largest-valid-sequence/
// construct the lexicographically largest valid sequence
class Solution {
public:    
    vector<int> constructDistancedSequence(int n) {
        vector<int> vis(n + 1);
        vector<int> res(n * 2 - 1);
        solve(vis, res, 0, n);
        return res;
    }    
    
    bool solve(vector<int>& vis, vector<int>& res, int cur, int n){
        
        if(cur == 2 *n - 1)
            return true;
         
        for(int num = n; num >= 1; num--){
            if(vis[num] == 1)
                continue;
            
            if(num != 1 && (cur + num >= 2 * n - 1 || res[cur + num] > 0))
                continue;
            
            vis[num] = 1;
            res[cur] = num;
            
            if(num != 1)
                res[cur + num] = num;    
            
            int offset = 1;
            while(cur + offset < 2 * n - 1 && res[cur + offset] != 0)
                offset++;
            if(solve(vis, res, cur + offset, n))
                return true;
            
            res[cur] = 0;
            if(num != 1)
                res[cur + num] = 0;
            vis[num] = 0;
        }
        return false;
    }
};