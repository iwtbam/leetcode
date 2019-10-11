class Solution {
    public int[] shortestToChar(String S, char C) {
        int len = S.length();
        int[] dis = new int[len];
        
        int eD = Integer.MAX_VALUE / 2;
        for(int i = 0; i < len; i++){
            if(S.charAt(i) == C)
                eD = 0;
            dis[i] = eD;
            eD++;
        }
        
        eD = Integer.MAX_VALUE / 2;
        
        for(int i = len - 1; i >=0;i--){
            if(S.charAt(i) == C)
                eD = 0;
            dis[i] = Math.min(eD, dis[i]);
            eD++;
        }
        
        return dis;
    }
}