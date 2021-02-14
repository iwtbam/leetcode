class Solution {
    public boolean isArmstrong(int N) {
        String s = String.valueOf(N);
        int k = s.length();
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            if(res  > N)
                return false;
            res += (int)Math.pow((s.charAt(i) - '0'), k);
        }
        
        return res == N;
    }
}