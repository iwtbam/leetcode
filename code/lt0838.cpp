#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int i = 0;
        while(dominoes[i]=='.')
            i++;
        int pre = i;

        if(dominoes[pre] == 'L')
        {
            for(int j = 0; j < i; j++)
                dominoes[j] = 'L';
        }
        
        int size = dominoes.size();

        for(i = i + 1; i < size ;i++)
        {
            char cur = dominoes[i]; 
            if(cur  =='.')
                continue;
            
            if(cur == dominoes[pre])
            {
                for(int j = pre + 1; j < i; j++)
                    dominoes[j] = cur;
            }
            else
            {
                int len = (i - pre -1)/2;
                if(cur == 'L')
                {
                    for(int j = 0; j < len; j++)
                    {
                        dominoes[pre +j + 1] = dominoes[pre];
                        dominoes[i - j - 1] = cur;
                    }
                }
            }
        
            pre = i;
        }
        
        if(dominoes[pre] =='R')
        {
           for(int i = pre; i < size; i++)
               dominoes[i] = 'R';
               
        }
        
        return dominoes;
    }
};