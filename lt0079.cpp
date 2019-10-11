#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        if(board.size() == 0)
            return false;
        
        vector<vector<int>> visited = {board.size(), vector<int>(board[0].size(), 0)};

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0;j < board[0].size(); j++)
                
                if(helper(board, visited, word, i, j, 0))
                    return true;
        }
        return false;
    }
    
    bool helper(vector<vector<char>>& board, vector<vector<int>>& visited, string& word, int i, int j , int step){
    
        int l1 = board.size();
        int l2 = board[0].size();
    
        if(step == word.size())
            return true;
        
        if(i >= l1 || j >= l2 || i <0 || j <0)
            return false;
        
        if(board[i][j]!=word[step])
            return false;

        if(visited[i][j])
            return false;

        visited[i][j] = 1;

        bool res = helper(board, visited, word, i+1, j, step+1) ||
                   helper(board, visited, word, i-1, j, step+1) ||
                   helper(board, visited, word, i, j+1, step+1) ||
                   helper(board, visited, word, i, j-1, step+1);
        if(res)
            return true;

         visited[i][j] = 0;
        
        return false;
    }
};