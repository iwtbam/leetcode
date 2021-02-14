// https://leetcode-cn.com/problems/find-latest-group-of-size-m/
// find latest group of size m
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        start.resize(n + 2, 0);
        len.resize(n + 2, 0);

        this->m = m;
        int last = -1;
        init();
        for(int i = 0; i < n; i++){
            int pos = arr[i];
            len[pos] = 1;

            merge(pos - 1, pos);
            merge(pos + 1, pos);

            if(len[start[pos]] == m){
                cans.insert(start[pos]);
            }

            if(cans.size() > 0)
                last = i + 1;
        }
        return last;
    }

    void init(){
        for(int i = 0; i < start.size(); i++)
            start[i] = i;
    }

    int parent(int n){
        if(start[n] == n)
            return n;
        return start[n] = parent(start[n]);
    }

    void merge(int n1, int n2){
        if(len[n1] == 0 || len[n2] == 0)
            return;
        
        int p1 = parent(n1);
        int p2 = parent(n2);
        
        if(cans.count(p1) == 1)
            cans.erase(p1);
        
        if(cans.count(p2) == 1)
            cans.erase(p2);

        len[p2] += len[p1];
    }

private:
    vector<int> start;
    vector<int> len;
    unordered_set<int> cans;
    int m, count;
};