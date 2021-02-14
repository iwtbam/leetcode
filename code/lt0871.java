// https://leetcode-cn.com/problems/minimum-number-of-refueling-stops/
// minimum number of refueling stops
class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        Queue<Integer> q = new PriorityQueue<Integer>((a, b) -> { return b - a; });
        int count = 0, pos = 0, fuel = startFuel;
        int len = stations.length;
        int[] finalStat = new int[]{target, 0};
        
        for(int i = 0; i <= len; i++){
            int[] stat = i == len ? finalStat : stations[i];
            // fuel = fuel - stat[0];
            while(fuel < stat[0] && q.size() > 0){
                fuel = fuel + q.poll();
                count++;
            }
            
            if(fuel < stat[0])
                return -1;
            q.offer(stat[1]);
        }
        
        return count;
    }
}