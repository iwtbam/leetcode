class Solution {
    public int countBinarySubstrings(String s) {
        int sum = 0;
        for(int i = 1; i < s.length();i++){
            if(s.charAt(i-1) != s.charAt(i)){
                int left = i - 1, right = i, offset = 1;
                sum += 1;
                while(left - offset >= 0 && right + offset < s.length() 
                    && s.charAt(left - offset) == s.charAt(i-1) && s.charAt(right + offset) == s.charAt(i)){
                        sum++;
                        offset++;
                    }
                i = right + offset - 1;
            }
        }
        
        return sum;
    }
}