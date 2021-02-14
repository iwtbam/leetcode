#include <vector>
#include <string>
#include <cstring>
#include <set>
using namespace std;


struct Trie
{
    const static  int kNodes = 26;
    string word;
    Trie* next[kNodes];

    Trie(){
        word = {};
        memset(next, 0, sizeof(next));
    }

    void insert(string& word){
        Trie* node = this;
        for(char w: word){
            if(node->next[w - 'a'] == nullptr){
                node->next[w - 'a'] = new Trie();
            }
            node = node->next[w - 'a'];
        }
        node->word = word;
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto word:words)
            root.insert(word);
        
        set<string> res;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
                helper(board, res, &root, i, j);
        }

        return {res.begin(),  res.end()};
    }

    void helper(vector<vector<char>>& board, set<string>& res, Trie* root, int i, int j)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j]=='.')
            return;

        char w = board[i][j];
        
        root = root->next[w - 'a'];

        if(root == nullptr)
            return;

        if(root->word != string{})
        {
            res.insert(root->word);
        }
            
        board[i][j] = '.';
        helper(board, res, root, i+1, j);
        helper(board, res, root, i-1, j);
        helper(board, res, root, i, j+1);
        helper(board, res, root, i, j-1);
        board[i][j] = w;

    }

private:
    Trie root;
};