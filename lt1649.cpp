// https://leetcode-cn.com/problems/create-sorted-array-through-instructions/
// create sorted array through instructions
class Solution {
public:
    
    vector<int> cnt;
    
    void change(int x, int n){
        while(x <= n){
            cnt[x] += 1;
            x += x & (-x);
        }
    }
    
    long long ask(int x){
        long long ans = 0;
        while(x){
            ans += cnt[x];
            x -= x&(-x);
        }
        return ans;
    }
    
    int createSortedArray(vector<int>& instructions) {     
        cnt.resize(100005, 0);
        long long ans = 0;
        size_t size = instructions.size();
        for(int i = 0; i < size; i++){
            int v = instructions[i];
            int lt = ask(v - 1);
            int gt = i - ask(v);
            int num = min(lt, gt);
            ans = (ans + num) % mod;
            
            change(v, 100005);
        }
        
         return ans;
    }
    
   
    
private:
    int mod = 1e9 + 7;
};