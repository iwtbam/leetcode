class Solution {
    public int titleToNumber(String s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++)
            res = res * 26 + s.charAt(i) - 'A' + 1;
        return res;
    }
}