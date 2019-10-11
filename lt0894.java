import java.util.*;

class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}



class Solution {
    
    private Map<Integer, List<TreeNode>> memo = new HashMap<>();
    
    public List<TreeNode> allPossibleFBT(int N) {
        
        
        if(memo.get(N)!=null)
            return memo.get(N);
        
        List<TreeNode> res = new ArrayList<>();
        
        if(N == 2 || N == 0){
            memo.put(N, res);
            return res;
        }
        
        if(N == 1){
            res.add(new TreeNode(0));
            memo.put(N, res);
            return res;
        }
        
        
        
        for(int i = 0; i < N - 1; i++){
            List<TreeNode> lt = allPossibleFBT(i);
            List<TreeNode> rt = allPossibleFBT(N - 1 - i);
            
            for(int j = 0; j < lt.size(); j++){
                for(int k = 0; k < rt.size(); k++){
                    TreeNode node = new TreeNode(0);
                    node.left = lt.get(j);
                    node.right = rt.get(k);
                    res.add(node);
                }
            }
            
        }
        
        memo.put(N, res);
        
        return res;
    }
}