#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Trie {
public:

    Trie* next[26];
    bool isEnd;

    Trie() {
        memset(next, 0, sizeof(next));
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* node = this;
        for(int i = 0; i < word.size(); i++)
        {
            if(node->next[word[i]-'a'] == nullptr)
            {
                node->next[word[i] - 'a'] = new Trie();
            }
            node = node->next[word[i] - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char w: word)
        {
            if(node->next[w - 'a'] == nullptr)
                return false;
            node = node->next[w - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        
        for(char w:prefix)
        {
            if(node->next[w - 'a'] == nullptr)
                return false;
            node = node->next[w-'a'];
        }

        return true;
    }

private:
    const static int kNodes = 26;
};