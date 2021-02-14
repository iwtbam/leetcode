// https://leetcode-cn.com/problems/super-pow/
// super pow
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int mod = 1337, size = b.size();
        long long ans = 1;
        for(int i = 0; i < size - 1; i++)
        {
            ans = ans * static_cast<long long>(my_pow(a % mod, b[i])) % mod;
            ans = static_cast<long long>(my_pow(ans, 10)) % mod;
        }

        return ans * static_cast<long long>(my_pow(a % mod, b[size - 1])) % mod;
    }
    
    int my_pow(int a, int n)
    {
        int ans = 1;
        for(int i = 0; i < n; i++)
            ans = (ans * a) % 1337;
        return ans;
    }
};