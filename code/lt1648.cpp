// https://leetcode-cn.com/problems/sell-diminishing-valued-colored-balls/
// sell diminishing valued colored balls
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        size_t size = inventory.size();
        sort(inventory.begin(), inventory.end());
        int l = 1, r = inventory.back();
        long long total = 0, pos = 0;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            pos = lower_bound(inventory.begin(), inventory.end(), mid) - inventory.begin();
            total = 0;
            for(int i = pos; i < size; i++)
                total += inventory[i] - mid + 1;
            
            if(total <= orders)
                r = mid;
            else
                l = mid + 1;
                
        }
        
        
        pos =  lower_bound(inventory.begin(), inventory.end(), l) - inventory.begin();
        total = 0;
        long long ans = 0;
        
        for(int i = pos; i < size; i++){
            ans = (ans +  (1LL * (l + inventory[i]) * (inventory[i] - l + 1) / 2) % mod) % mod;
            total += inventory[i] - l + 1;
        }
        
        if(orders > total){
            ans = (ans + ((orders - total) * (l - 1)) % mod) % mod;
        }
        
        return ans;
    }
    
    
private:
    int mod = 1e9 + 7;
};