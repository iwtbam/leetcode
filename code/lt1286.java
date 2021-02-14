// https://leetcode-cn.com/problems/iterator-for-combination/
// iterator for combination
class CombinationIterator {

    public CombinationIterator(String characters, int combinationLength) {
        chs = characters.toCharArray();
        dfs("", 0, combinationLength);
    }
    
    public String next() {
        return q.poll();
    }
    
    public boolean hasNext() {
        return q.size() > 0;
    }
    
    public void dfs(String s, int step, int len){
        if(len == 0){
            // System.out.println(s);
            q.offer(s);
            return;
        }
        
        for(int i = step; i < chs.length; i++){
            dfs(s + chs[i], i + 1, len - 1);
        }
    }
    
    private Queue<String> q = new LinkedList<>();
    private char[] chs = null;
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator obj = new CombinationIterator(characters, combinationLength);
 * String param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */