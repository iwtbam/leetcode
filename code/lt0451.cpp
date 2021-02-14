#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> record;
        for(char c:s)
            record[c]++;
        vector<pair<char, int>> record2(record.begin(), record.end());
        sort(record2.begin(), record2.end(), [](const pair<char, int>& p1, const pair<char, int>& p2){
           if(p1.second == p2.second)
               return p1.first  < p2.first;
            return p1.second > p2.second;
        });
        
        string res = {};
        
        for(auto& p : record2){
            res += string(p.second, p.first);
        }
        return res;
    }
};