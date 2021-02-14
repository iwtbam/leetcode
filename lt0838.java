// https://leetcode-cn.com/problems/push-dominoes/
// push dominoes
class Solution {
    public String pushDominoes(String dominoes) {
        int len = dominoes.length();
        char[] temp = dominoes.toCharArray();
        int p = -1;
        for(int i = 0; i < len; i++){
            char cur = temp[i];
            if(cur == '.')
                continue;
            char pre = p!=-1 ? temp[p] : 'L';
            
            if(cur == pre){
                for(int j = p + 1; j < i; j++)
                    temp[j] = cur;
            }
            
            if(pre == 'R' && cur == 'L'){
                int l = p + 1;
                int r = i - 1;
                while(l < r){
                    temp[l++] = 'R';
                    temp[r--] = 'L';
                }
            }
            
            p = i;
        }
        
        if(p!=-1 && temp[p] == 'R'){
            for(int i = p + 1; i < len; i++)
                temp[i] = 'R';
        }
        
        return String.valueOf(temp);
    }
}