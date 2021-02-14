// https://leetcode-cn.com/problems/group-the-people-given-the-group-size-they-belong-to/
// group the people given the group size they belong to
class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        Map<Integer, List<Integer>> record = new HashMap<>();
        int len = groupSizes.length;
        for(int i = 0; i < len; i++){
            int size = groupSizes[i];
            if(!record.containsKey(size))
                record.put(size, new ArrayList<>());
            record.get(size).add(i);
        }
        
        List<List<Integer>> res = new ArrayList<>();
        for(int key : record.keySet()){
            List<Integer> gs = record.get(key);
            int size = gs.size();
            for(int i = 0; i < size; i += key){
                List<Integer> group = new ArrayList<>();
                for(int j = 0; j < key && i + j < size ; j++){
                    group.add(gs.get(i + j));
                }
                res.add(group);
            }
        }
        
        return res;
    }
}