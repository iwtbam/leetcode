// https://leetcode-cn.com/problems/rearrange-string-k-distance-apart/
// rearrange string k distance apart
using PII = pair<int, int>;

namespace std {
    template<>
    struct less<PII>
    {
        bool operator()(const PII& p1, const PII& p2){
            return p1.first == p2.first ? p1.second > p2.second : p1.first < p2.first;
        }
    };
}


class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k == 0){
            sort(s.begin(), s.end());
            return s;
        }
        priority_queue<PII> q;
        queue<PII> aq;
        vector<int> record(26);
        size_t size = s.size();
        
        for(int i = 0; i < size; i++)
            record[s[i] - 'a']++;

        int bucket = size / k + (size % k == 0 ? 0 : 1);


        for(int i = 0; i < 26; i++){
            if(record[i] != 0){
                if(record[i] > bucket)
                    return "";
                q.emplace(record[i], i);
            }
        }
        string res;
        while(q.size()){
            int i = 0;
            while(i < k && q.size()){
                auto top = q.top();
                
                res.push_back(top.second + 'a');
                top.first--;
                q.pop();
                
                if(top.first > 0)
                    aq.push(top);
                i++;
            }

            if(i < k && aq.size() > 0)
                return "";

            while(aq.size()){
                q.push(aq.front());
                aq.pop();
            }
        }
        return res;
    }
};