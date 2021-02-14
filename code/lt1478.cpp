// https://leetcode-cn.com/problems/allocate-mailboxes/
// allocate mailboxes
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        size_t n = houses.size();
        vector<vector<int>> dis = {n, vector<int>(n, 0)};
        
        sort(houses.begin(), houses.end());

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int pi = i, pj = j;
                int sum = 0;
                while(pi < pj){
                    sum += houses[pj] - houses[pi];
                    pj--;
                    pi++;
                }
                dis[i][j] = sum;
            }
        }

        vector<vector<int>> dp = {n, vector<int>(k + 1, INT_MAX)};

        for(int i = 0; i < n; i++){
            dp[i][1] = dis[0][i];
          //  cout << dis[0][i] << endl;
        }

        for(int i = 1; i < n; i++){
            for(int s = 2; s <= min(k, i + 1); s++){
                for(int j = s - 2; j < i; j++){
                    if(dp[j][s - 1] == INT_MAX)
                        continue;
                    dp[i][s] = min(dp[i][s], dp[j][s - 1] + dis[j + 1][i]);
                }
            }
        }

        return dp[n - 1][k];
    }
};