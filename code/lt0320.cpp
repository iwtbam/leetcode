#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int size = word.size();
        
        if(size == 0)
            return {};

        int total = 1 << size;

        vector<string> res = {};

        for(int i = 0; i < total; i++){
            res.push_back(helper(word, i));
        }

        return res;
    }

    string helper(const string& word, int index){
        string res = {};
        int size = word.size();
        int bit = 1;
        int offset = 0;
        for(int i = 0; i < size; i++)
        {
            if(bit & index){
                offset++;
            }else{
                if(offset){
                    res += to_string(1 << offset);
                }
                res.push_back(word[i]);
                offset = 0;
            }
        }

        if(offset)
            res += to_string(1 << offset);
        
        return move(res);
    }
};