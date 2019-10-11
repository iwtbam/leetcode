#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    
    vector<int> Fact = {};

    vector<int> fact(int n)
    {
        vector<int> dp = {1};
        for(int i = 1; i <= n; i++)
            dp.push_back( i * dp[i-1]);
        return dp;
    }
    
    
    
    string getPermutation(int n, int k) {
        vector<bool> visited(n, 0);
        Fact =fact(10);
        string res;
        int step = 0;
        helper(res, visited, n, k, step);
        return res;
    }
    
    bool helper(string& record, vector<bool>& visited, int n, int k, int& step)
    {
        
        if(record.size() == n)
        {
            step++;
            if(step == k)
                return true;
        }
        

        int ps = Fact[n - record.size() - 1];
        
        for(int i = 0; i < n; i++)
        {
            if(visited[i])
                continue;

            if(step + ps < k)
            {
                step += ps;
                continue;
            }
            
            record.push_back(i+'1');
            visited[i] = 1;
            if(helper(record, visited, n, k, step))
                return true;
            visited[i] = 0;
            record.pop_back();
        }
        
        return false;
    }
};