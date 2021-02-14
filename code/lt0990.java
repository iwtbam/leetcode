// https://leetcode-cn.com/problems/satisfiability-of-equality-equations/
// satisfiability of equality equations
class Solution {
    public boolean equationsPossible(String[] equations) {
        nums = new int[26];
        rank = new int[26];
        
        init();
        
        int L = equations.length;
        
        for(int i = 0; i < L; i++){
            char[] chs = equations[i].toCharArray();
            int n1 = chs[0] - 'a';
            int n2 = chs[3] - 'a';
            char op = chs[1];
            if(op == '=')
                merge(n1, n2);
        }
        
        
        for(int i = 0; i < L; i++){
            char[] chs = equations[i].toCharArray();
            int n1 = chs[0] - 'a';
            int n2 = chs[3] - 'a';
            char op = chs[1];
            if(op == '!' && parent(n1) == parent(n2))
                return false;
        }
        
        return true;
    }
    
    public void init(){
        for(int i = 0; i < 26; i++){
            nums[i] = i;
        }
    }
    
    public int parent(int n){
        return nums[n] == n ? n : parent(nums[n]);
    }
    
    public void merge(int n1, int n2){
        int p1 = parent(n1);
        int p2 = parent(n2);
        
        
        if(p1 == p2)
            return;
        
        if(rank[p1] < rank[p2]){
            nums[p1] = p2;
        }else{
            if(rank[p1] == rank[p2])
                rank[p1]++;
            nums[p2] = p1;
        }
    }
    
    private int[] nums = null;
    private int[] rank = null;
}