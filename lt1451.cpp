// https://leetcode-cn.com/problems/rearrange-words-in-a-sentence/
// rearrange words in a sentence
class Solution {
public:
    string arrangeWords(string text) {
        int start = 0;
        size_t size = text.size();
        vector<pair<int, int>> words;
        text[0] = text[0] - 'A' + 'a';
        for(int i = 0; i < size; i++){
            if(text[i] == ' '){
                words.emplace_back(start, i - start);
                start = i + 1;
            }
        }
        words.emplace_back(start, size - start);
        stable_sort(words.begin(), words.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second < p2.second;
        });

        string res = move(text.substr(words[0].first, words[0].second));

        int num = words.size();

        for(int i = 1; i < num; i++){
            res.append(" ");
            res.append(text, words[i].first, words[i].second);
        }

        res[0] = res[0] - 'a' + 'A';
        return res;

    }
};