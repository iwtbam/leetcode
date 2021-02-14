// https://leetcode-cn.com/problems/minimum-genetic-mutation/
// minimum genetic mutation
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        size_t size = bank.size();
        
        unordered_set<string> record;
        unordered_set<string> vis;

        for(int i = 0; i < size; i++){
            record.insert(bank[i]);
        }

        int step = solve(start, end, vis, record);
        return step == UN_SOLVE ? -1 : step;
    }

    int solve(string& cur, string& target, unordered_set<string>& vis, unordered_set<string>& record){
        if(cur == target){
            return 0;
        }

        if(memos.count(cur))
            return memos[cur];

        size_t n = cur.size();
        int step = UN_SOLVE;
        for(int i = 0; i < n; i++){
            char old = cur[i];
            for(int j = 0; j < 4; j++){
                if(old == seq[j])
                    continue;
                cur[i] = seq[j];
                if(record.count(cur) && !vis.count(cur)){
                    vis.insert(cur);
                    step = min(step, solve(cur, target, vis, record));
                    vis.erase(cur);
                }
            }
            cur[i] = old;
        }

        memos[cur] =  step == UN_SOLVE ? step : step + 1;
        return memos[cur];
    }

private:
    unordered_map<string, int> memos;
    vector<char> seq = {'A', 'C', 'G', 'T'};
    const int UN_SOLVE = INT_MAX;
};