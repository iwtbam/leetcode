#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> record = {};
        vector<int> res = {};
        for(int i = 0; i < S.size(); i++)
            record[S[i]] = i;
        int left = 0, right = -1;
        for(int i = 0; i < S.size(); i++)
        {
            if(i < right && record[S[i]] > right)
                right = record[S[i]];
            
            if(right == -1)
                right = record[S[i]];
            
            if(i == right)
            {
                res.push_back(right - left + 1);
                left = right + 1;
                right = record[S[left]];
            }
        }
        
        return res;
    }
};