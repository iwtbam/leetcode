// https://leetcode-cn.com/problems/delete-tree-nodes/
// delete tree nodes
class Solution {
    public int deleteTreeNodes(int nodes, int[] parent, int[] value) {
        List<Integer>[] trees = new ArrayList[nodes];
        
        int p = 0;
        
        for(int i = 0; i < nodes; i++)
            trees[i] = new ArrayList<>();
        
        for(int i = 0; i < nodes; i++){
            if(parent[i] == -1)
                p = i;
            else
                trees[parent[i]].add(i);
        }
        
        int[] res = helper(trees, p, value);
        
        return res[1];
    }
    
    public int[] helper(List<Integer>[] trees, int node, int[] vals){
        
        int sum = vals[node];
        int num = 1;
        int size = trees[node].size();
        for(int i = 0; i < size; i++){
            int[] res = helper(trees, trees[node].get(i), vals);
            sum += res[0];
            num += res[1];
        }
        
        
        if(sum == 0)
            num = 0;
        
        // System.out.println(sum + " " + num);

        return new int[]{sum, num};
    }
    
    
}