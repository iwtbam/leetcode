// https://leetcode-cn.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
// form largest integer with digits that add up to target
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
   
        string cur = {};
        
        map<int, string> record;
        
        size_t size = cost.size();
        
        vector<string> dp(target + 1, "0");
        dp[0] = "";
        
        for(int i = 0; i < 9; i++){
            record[cost[i]] = to_string(i + 1);
        }
        
        vector<pair<int, string>> unique_cost = {record.begin(), record.end()};        
       
        for(int i = 0; i < size; i++){
            int c = cost[i];
            string v = to_string(i + 1);
            for(int i = c; i <= target; i++){
                if(dp[i - c] == "0")
                    continue;
                string temp = dp[i - c] + v;
                if(cmp(dp[i], temp))
                    dp[i] = temp;
                
                
                temp = v + dp[i - c];
                
                if(cmp(dp[i], temp))
                    dp[i] = temp;
            }
        }
        
        
        return dp[target];
    }
    
    inline bool cmp(const string& a, const string& b){
        if(a.size() == b.size())
            return a < b;
        return a.size() < b.size();
    }
};