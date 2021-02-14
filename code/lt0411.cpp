#include <vector>
#include <string>
#include <cctype>
using namespace std;

//2019-07-12:这并算很难得题,但我没想起用回溯,我菜

class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary){
        int len = target.size();
        vector<string> words = {};
        for(const auto& word: dictionary){
            if(len == word.size())
                words.push_back(word);
        }

        if(words.empty())
            return to_string(len);

        string res = target;

        dfs({}, target, 0, words, res, len);

        return res;
    }


    void dfs(string cur, const string& target, int pos, const vector<string>& words, string& res, int& min_len){
    
        if(pos >= target.size()){
            int cur_len = cur.size();
            if(cur_len < min_len){
                bool is_valid = true;
                for(const string& s:words){
                    if(check(s, cur)){
                        is_valid = false;
                        break;
                    }
                }
                if(is_valid){
                    res = cur;
                    min_len = cur_len;
                }
                return;
            }
        }

        if(cur.size() >= min_len)
            return;

        if(cur.empty() || !isdigit(cur.back())){
            for(int i = target.size() - 1; i >= pos; i--){
                dfs(cur + to_string(i - pos + 1), target, i + 1, words, res, min_len);
            }
        }

        dfs(cur + target[pos], target, pos + 1, words, res, min_len);
        return;
    
    }

    bool check(string s1, string s2){
        int len1 = s1.size();
        int len2 = s2.size();
        int l = 0, r = 0;
        while(l <  len1 && r < len2){
            if(isdigit(s2[r])){
                int dis = 0;
                while(r < len2 && isdigit(s2[r])){
                    dis = dis * 10 + s2[r++] - '0';
                }
                l += dis;
            }
            else if(s2[r] == '0')
                return false;
            else
            {
                if(s1[l] == s2[r])
                    l++, r++;
                else
                    return false;
            }
        }

        if(l >= len1 && r >= len2)
            return true;
        return false;
    }
};