// https://leetcode-cn.com/problems/image-overlap/
// image overlap
class Solution {
    public int largestOverlap(int[][] A, int[][] B) {
        Map<Integer, Integer> record = new HashMap<>();
        int N = A.length;
        List<Integer> aOnes = new ArrayList<>();
        List<Integer> bOnes = new ArrayList<>();
        for(int i = 0; i < N * N; i++){
            int r = i / N, c = i % N;
            if(A[r][c] == 1)
                aOnes.add(r * 197 + c);
            if(B[r][c] == 1)
                bOnes.add(r * 197 + c);
        }

        int res = 0;

        for(int a : aOnes){
            for(int b : bOnes){
                record.put(b - a, record.getOrDefault(b - a, 0) + 1);
            }
        }

        for(int v : record.values())
            res = Math.max(res, v);

        return res;
    }
}