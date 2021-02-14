// https://leetcode-cn.com/problems/find-and-replace-in-string/
// find and replace in string
class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        int len = indexes.length;
        if(len == 0)
            return S;
        
        Map<Integer, String[]> record = new TreeMap<>();
        
        for(int i = 0; i < len; i++){
            record.put(indexes[i], new String[]{sources[i], targets[i]});
        }
        
        StringBuffer sb = new StringBuffer();
        int pre = 0;
        
        for(Map.Entry<Integer, String[]> entry : record.entrySet()){
            int start  = entry.getKey();
            String[] words = entry.getValue();
            String src = words[0];
            
            if(!src.equals(S.substring(start, start + src.length())))
                continue;
            sb.append(S.substring(pre, start));
            sb.append(words[1]);
            pre = start + src.length();
        }
        
        sb.append(S.substring(pre, S.length()));
        
        return sb.toString();
    }
}