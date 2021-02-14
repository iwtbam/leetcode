// https://leetcode-cn.com/problems/two-city-scheduling/
// two city scheduling
class Solution {
    public int twoCitySchedCost(int[][] costs) {
       int twoN = costs.length;
       int[] diff = new int[twoN];
       int sum = 0;
       for(int i = 0;i < twoN; i++){
           sum += costs[i][0];
           diff[i] = costs[i][1] - costs[i][0];
       }

       Arrays.sort(diff);

       int diffSum = 0;
       for(int i = 0; i < twoN / 2; i++){
           diffSum += diff[i];
       }

       return sum + diffSum;
    }
}