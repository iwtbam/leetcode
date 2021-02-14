// https://leetcode-cn.com/problems/number-of-squareful-arrays/
// number of squareful arrays
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        size_t size = A.size();
        vector<int> vis(size, 0);
        vector<int> path;
        return solve(A, vis, path);
    }

    int solve(vector<int>& A, vector<int>& vis, vector<int>& path){
        if(path.size() == A.size()){
            return 1;
        }
        int num = 0;
        size_t size = A.size();
        unordered_set<int> repeat;
        
        for(int i = 0; i < size; i++){
          
            if(vis[i] == 1 || repeat.count(A[i]))
                continue;
            
            if(path.size() > 0 && !isSq(path.back() + A[i])){
                continue;
            }
         
            vis[i] = 1;
            path.push_back(A[i]);
            num += solve(A, vis, path);
            path.pop_back();
            vis[i] = 0;
            repeat.insert(A[i]);
        }
        
        return num;
    }

    bool isSq(int num){
        int target = pow(static_cast<int>(sqrt(num)), 2);
        return num == target; 
    }
};