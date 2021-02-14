// https://leetcode-cn.com/problems/find-duplicate-file-in-system/
// find duplicate file in system
class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> record = new HashMap<>();
        for(int i = 0; i < paths.length; i++){
            String path = paths[i];
            String[] items = path.split(" ");
            String dir = items[0];
            int num = items.length;
            for(int j = 1; j < num; j++){
                String[] strs = items[j].split("\\(");
                String filename = strs[0];
                String content = strs[1].substring(0, strs[1].length() - 1);
                if(!record.containsKey(content))
                    record.put(content, new ArrayList<>());
                record.get(content).add(dir + '/' + filename); 
            }
        }

        List<List<String>> res = new ArrayList<>();
        for(List<String> val : record.values()){
            if(val.size() > 1)
                res.add(val);
        }
        return res;
    }
}