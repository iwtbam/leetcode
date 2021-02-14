// https://leetcode-cn.com/problems/words-frequency-lcci/
// words frequency lcci
class WordsFrequency {
public:
    WordsFrequency(vector<string>& book) {
        size_t size = book.size();
        for(int i = 0; i < size; i++){
            hash[book[i]]++;
        }
    }
    
    int get(string word) {
        if(hash.count(word))
            return hash[word];
        return 0;
    }
private:
    unordered_map<string, int> hash;
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */