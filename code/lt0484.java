// https://leetcode-cn.com/problems/find-permutation/
// find permutation
class Solution {
    public int[] findPermutation(String s) {
        int L = s.length();
        if(L == 0)
            return null;

        char[] chs = s.toCharArray();
        int[] res = new int[L + 1];
        for(int i = 0; i <=L; i++)
            res[i] = i + 1;

        for(int i = 1; i <= L; i++){
            if(chs[i - 1] == 'I')
                continue;
            int pi = i;
            while(i <= L && chs[i - 1] == 'D')
                i++;
            reverse(res, pi - 1, i - 1);
        }

        return res;
    }

    public void reverse(int[] res, int i, int j){
        while(i < j && j < res.length){
            res[i] = res[i] ^ res[j];
            res[j] = res[i] ^ res[j];
            res[i] = res[i] ^ res[j];
            i++;
            j--;
        }
    }
}