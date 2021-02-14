// https://leetcode-cn.com/problems/lexicographical-numbers/
// lexicographical numbers
class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        helper(0, n, res);
        return res;
    }

    public void helper(int prefix, int n, List<Integer> res){
        if(prefix > n)
            return;
        
        if(prefix!=0)
            res.add(prefix);

        for(int i = 0; i <= 9; i++){
            if(prefix == 0 && i == 0)
                continue;
            helper(prefix * 10 + i, n, res);
        }
    }
}