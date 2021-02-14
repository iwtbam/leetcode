// https://leetcode-cn.com/problems/group-anagrams/
// group anagrams
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int size = strs.length;
        
        Map<String, List<String>> cons = new HashMap<>();
        for(int i = 0; i < size; i++){
            String key = toKey(strs[i].toCharArray());
            if(!cons.containsKey(key)){
                cons.put(key, new ArrayList<String>());
            }
            cons.get(key).add(strs[i]);
        }
        
        List<List<String>> res = new ArrayList<>();
        for(List<String> item : cons.values()){
            res.add(item);
        }

        return res;
    }

    public String toKey(char[] str){
        int[] record = new int[26];
        
        for(int i = 0; i < str.length; i++){
            record[str[i] - 'a']++;
        }

        StringBuffer sb = new StringBuffer();
        
        for(int i = 0; i < 26; i++){
            sb.append('#');
            sb.append(record[i]);
        }

        return sb.toString();
    }
}