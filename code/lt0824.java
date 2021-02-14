// https://leetcode-cn.com/problems/goat-latin/
// goat latin
class Solution {
    public String toGoatLatin(String S) {
        StringBuffer res = new StringBuffer();
        String[] words = S.split(" ");
        int count = 1;
        for(int i = 0; i < words.length; i++){
            String nword = deal(words[i], i + 1);
            res.append(nword);
            if(i!=words.length - 1)
                res.append(" ");
        }

        return res.toString();
    }

    public String deal(String s, int num){
        StringBuffer res =  new StringBuffer();
        char c = s.charAt(0);
        if(c == 'a' || c == 'o' || c == 'i' || c== 'u' || c == 'e' ||
           c == 'A' || c == 'O' || c == 'I' || c== 'U' || c == 'E')
            res.append(s);
        else
            res.append(s.substring(1) + c);

        res.append("ma");
        
        for(int i = 0; i < num; i++){
            res.append('a');
        }

        return res.toString();
    }
}