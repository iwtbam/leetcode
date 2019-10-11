#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    bool flag = false;
    
    vector<vector<int>> rows = {9, vector<int>(10, 0)};
    vector<vector<int>> cols = {9, vector<int>(10, 0)};
    vector<vector<int>> areas = {9, vector<int>(10, 0)};
    
    void solveSudoku(vector<vector<char>>& board) {
        int total = countSpace(board);
        
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j]=='.')
                    continue;
                rows[i][board[i][j] - '0'] = 1;
                cols[j][board[i][j] - '0'] = 1;
                int index = (i / 3) * 3 + j / 3;
                areas[index][board[i][j]-'0'] = 1;
            }
        }
        
        cout << total << endl;
        helper(board, 0, 0);
        return;
    }
    
    void helper(vector<vector<char>>& board, int i, int j){
        
        while(board[i][j]!='.')
        {
            if(++j>=9)
            {
                i++;
                j = 0;
            }
            
            if(i>=9)
            {
                flag = true;
                return;
            }
        }
        
                
        for(int k = 1; k <=9 ;k++)
        {
            int index = (i/3)*3 + j/3;
            if(rows[i][k] || cols[j][k] || areas[index][k])
                continue;
            rows[i][k] = 1;
            cols[j][k] = 1;
            areas[index][k] = 1;
            board[i][j] = '0' + k;
            helper(board, i, j);
            if(flag)
                return;
            board[i][j] = '.';
            rows[i][k] = 0;
            cols[j][k] = 0;
            areas[index][k] = 0;
        }
        
    
       
    }
    
    
    int countSpace(vector<vector<char>>& board){
        int num = 0;
        
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j]=='.')
                    num++;
            }
        }
        
        return num;
    }
};