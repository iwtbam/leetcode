// https://leetcode-cn.com/problems/map-sum-pairs/
// map sum pairs
class MapSum {

    class Node {
        Map<Character, Node> nexts;
        int val;
        Node(int val){
            nexts = new HashMap<>();
            this.val = val;
        }
    }


    
    /** Initialize your data structure here. */
    public MapSum() {
        root = new Node(0);
    }
    
    public void insert(String key, int val) {
        Node cur = root;
        for(int  i = 0; i < key.length(); i++){
            char c = key.charAt(i);
            if(cur.nexts.getOrDefault(c, null) == null){
                cur.nexts.put(c, new Node(0));
            }
            cur = cur.nexts.get(c);
        }
        cur.val = val;
    }
    
   public int sum(String prefix){
        Node cur = root;
        for(int i = 0; i < prefix.length(); i++){
            char c = prefix.charAt(i);
            if(cur.nexts.get(c) == null)
                return 0;
            cur = cur.nexts.get(c);
        }

        return sum(cur);
    }
    
   
    public int sum(Node node){
        if(node.nexts.size() == 0){
            return node.val;
        }

        int res = node.val;

        for(char c : node.nexts.keySet()){
            res += sum(node.nexts.get(c));
        }

        return res;
    }
    
    private Node root;
    
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */