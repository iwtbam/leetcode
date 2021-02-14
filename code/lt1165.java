import java.util.*;

class Solution {
    public int calculateTime(String keyboard, String word) {
        Map<Character, Integer> pos = new HashMap<>();
        for(int i = 0; i < keyboard.length(); i++)
            pos.put(keyboard.charAt(i), i);
        int pre = 0;
        int cost = 0;
        for(int i = 0; i < word.length(); i++){
            cost += Math.abs(pos.get(word.charAt(i)) - pre);
            pre = pos.get(word.charAt(i));
        }
        
        return cost;
    }
}