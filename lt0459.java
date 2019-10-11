class Solution {
    public boolean repeatedSubstringPattern(String s) {
        String target = s + s;
        return target.substring(1, target.length() - 1).contains(s);
    }
}