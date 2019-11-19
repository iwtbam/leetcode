class Solution {
    public boolean queryString(String S, int N) {
        for(int i=1;i<=N;i++){
            String bin=Integer.toBinaryString(i);
            if(S.indexOf(bin)==-1) return false;
        }
        return true;
    }
}