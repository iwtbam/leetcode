// https://leetcode-cn.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/
// minimum possible integer after at most k adjacent swaps on digits
class Solution {
public:
    string minInteger(string num, int k) {
        
        string sorted = num;
        sort(sorted.begin(), sorted.end());
        if(sorted == num)
            return num;
        
        size_t size = num.size();

        if(k >= size * (size - 1) / 2)
            return sorted;
        
        
        vector<queue<int>> record = {10L, queue<int>()};
        string res;
        vector<int> vis(size, 0);
        set<int> s;
        
        for(int i = 0; i < size; i++){
            record[num[i] - '0'].push(i);
        }
        
        for(int i = 0; i < size; i++){
            for(int j = 0; j < 10; j++){
                if(record[j].size() == 0)
                    continue;
                int index = record[j].front();
                int d = dis(s, 0, index);
                if(d > k)
                    continue;
                
                res.push_back(j + '0');
                k -= d;
                //cout << j << " index: " << index << " dis " << d << " k " << k << endl;
               
                vis[index] = 1;
                record[j].pop();
                s.insert(index);
                break;
            }
        }
        
        for(int i = 0; i < size; i++){
            if(vis[i] == 0)
                res.push_back(num[i]);
        }
        
        return res;
    }
    
    int dis(set<int>& s,  int cur, int index){
        size_t size = s.size();
        int n = distance(s.upper_bound(index), s.end());
      //  cout << size << " " <<  n << endl;
        return (index - cur) - (size - n);
    }
};