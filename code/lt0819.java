// https://leetcode-cn.com/problems/most-common-word/
// most common word
class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> record = new HashSet<>();
        Map<String, Integer> count = new HashMap<>();

        for(String bann : banned){
            record.add(bann.toLowerCase());
        }

        record.add("");

        String[] words = paragraph.split("[\\s!?',;.]");

        for(String word : words){
            String key = word.toLowerCase();
            // System.out.println(key);
            // if(key == "")
                // System.out.println("null");
            if(!record.contains(key)){
                // System.out.println(key);
                count.put(key, count.getOrDefault(key, 0) + 1);
                // System.out.println(key + "|" + count.get(key));
            }
        }

        String res = null;
        int num = 0;

        for(String key : count.keySet()){
            // System.out.println(key);
            // System.out.println(key + " " + count.get(key));
            if(count.get(key) > num){
                num = count.get(key);
                res = key;
            }
        }

        return res;
    }
}