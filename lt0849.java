class Solution {
    public int maxDistToClosest(int[] seats) {
        int len = seats.length;    
        int dis = 0, pre = -1;
        
        for(int i = 0; i < len; i++){
            if(seats[i] == 1){
                if(i == pre + 1){
                    pre = i;
                    continue;
                }
                
                if(pre == -1)
                    dis = i;
                
                dis = Math.max(dis, (i - pre)/2);
                pre = i;
            }
        }
        
        dis = Math.max(dis, len - pre - 1);
        return dis;
    }
}