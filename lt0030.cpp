#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        if(words.empty())
            return {};
        
        int word_size = words.size();
        int one_word_len = words[0].size();
        int total_len = word_size * words[0].size();
        unordered_map<string, int> record = {};
        unordered_map<string, int> counter = {};
        vector<int> res = {};
        for(const string& word:words){
            record[word]++;
        }

        if(total_len > s.size())
            return {};

        int max_size = s.size() - total_len;
        
        for(int i = 0; i <= max_size; i++)
        {
           
            int j = 0;
            counter = {};
            for(; j < word_size; j++)
            {
                string temp = s.substr(i + j * one_word_len, one_word_len);
                if(record[temp]){
                    counter[temp]++;
                   
                    if(counter[temp] > record[temp]){
                        break;
                    };
                }
                else
                    break;

            }
            
            if(j == word_size){
                res.push_back(i);
               
            }
        }

        return res;
    }
};