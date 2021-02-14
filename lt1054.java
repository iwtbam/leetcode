// https://leetcode-cn.com/problems/distant-barcodes/
// distant barcodes
class Solution {
    
    
    public int[] rearrangeBarcodes(int[] barcodes) {
        int len = barcodes.length;
        Map<Integer, Integer> count = new HashMap<>();
        for(int i = 0; i < len; i++){
            count.put(barcodes[i], count.getOrDefault(barcodes[i], 0) + 1);
        }
        
        List<int[]> nums = new ArrayList<>();
        
        for(int key : count.keySet()){
            nums.add(new int[]{key, count.get(key)});
        }
        
        
        Collections.sort(nums, new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return b[1] - a[1];
            }
        });
        
        int[] res = new int[len];
        int i = 0;
        for(int[] num : nums){
            for(int n = 0; n < num[1]; n++){
                res[i] = num[0];
                i += 2;
                if(i >= len)
                    i = 1;
            }
        }
        
        return res;
    }
}