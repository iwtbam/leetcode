// https://leetcode-cn.com/problems/lexicographically-smallest-string-after-applying-operations/
// lexicographically smallest string after applying operations
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> record;
        string ans = s;
        size_t size = s.size();
        b = b % size;
        queue<string> q;
        q.push(s);
        record.insert(s);
        while(q.size()){
            string t1 = q.front();
            //cout << t1 << endl;
            q.pop();

            string t2 = t1.substr(size - b) + t1.substr(0, size - b);
            
            for(int i = 1; i < size; i+= 2){
                t1[i] = (t1[i] - '0' + a) % 10 + '0';
            }
            
            if(record.count(t1) == 0){
                ans = min(ans, t1);
                q.push(t1);
                record.insert(t1);
            }
            
            if(record.count(t2) == 0){
                ans= min(ans, t2);
                q.push(t2);
                record.insert(t2);
            }
            
        }
        
        return ans;
    }
    
    
};