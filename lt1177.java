import java.util.*;

class Solution {
    public List<Boolean> canMakePaliQueries(String s, int[][] queries) {
        int len = s.length();
        List<Boolean> res = new ArrayList<>();
        
        if(len == 0)
            return res;
        
        int[][] hashes = new int[len + 1][26];
        for(int i = 1; i < len + 1; i++){
            System.arraycopy(hashes[i - 1], 0, hashes[i], 0, 26);
            hashes[i][s.charAt(i - 1) - 'a']++;
        }

        for(int[] query : queries){
            int left = query[0];
            int right = query[1] + 1;
            int ans = 0;
            for(int i = 0; i < 26; i++)
                ans +=  (hashes[right][i] - hashes[left][i]) % 2;
            if((right - left) % 2 == 1)
                ans--;
            
            res.add((ans + 1)/2 <= query[2]);
        }

        return res;
    }
}