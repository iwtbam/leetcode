// https://leetcode-cn.com/problems/remove-sub-folders-from-the-filesystem/
// remove sub folders from the filesystem
class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        List<String> res = new ArrayList<>();
        res.add(folder[0]);
        String pre = folder[0];
        int ps = pre.length();
        
        for(int i = 1; i < folder.length; i++){
            String cur = folder[i];
            int index = cur.indexOf("/", ps);
            
            if(index!=-1 && cur.substring(0, index).equals(pre))
                continue;
        
            // System.out.println(pre);

            res.add(cur);
            pre = cur;
            ps = cur.length();
        }
        
        return res;
    }
}