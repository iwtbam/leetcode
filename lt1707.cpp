// https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array/
// maximum xor with an element from array
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        size_t m = queries.size();
        size_t n = nums.size();
        vector indexs(m, 0);

        iota(indexs.begin(), indexs.end(), 0);
        
        sort(indexs.begin(), indexs.end(), [&](const int i, const int j){
            return queries[i][1] < queries[j][1];
        });
        sort(nums.begin(), nums.end());
        
        vector<int> res(m, 0);
        int i = 0, j = 0;

        while(i < n && j < m){
            int pos = indexs[j];
            if(nums[i] > queries[pos][1]){
                if(i == 0){
                    res[pos] = -1;
                }else{
                    res[pos] = queries[pos][0] ^ search(queries[pos][0]);
                }
                j++;
                continue;
            }
            insert(nums[i]);
            i++;
        }

        while(j < m){
            int pos = indexs[j];
            res[pos] = queries[pos][0] ^ search(queries[pos][0]);
            j++;
        }
        return res;
    }

    void insert(int num){
        int cur = root;
        for(int k = 29; k >= 0; k--){
            int c = num >> k & 1;
            if(trie[cur][c] == 0)
                trie[cur][c] = ++tot;
            cur = trie[cur][c];
        }
    }

    int search(int num){
        int ans = 0, cur = root;
        for(int k = 29; k >= 0; k--){
            int c = num >> k & 1;
            
            if(trie[cur][c ^ 1]){
                ans = ans * 2 + c ^ 1;
                cur = trie[cur][c ^ 1];
            }else{
                ans = ans * 2 + c;
                cur = trie[cur][c];
            }
        }
        return ans;
    }


private:
    int tot = 0;
    int root = 0;

    const static int N = 1e5 + 10;
    int trie[N * 30 + 1][2] = {0};

};