class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int state = 0;
        for(int i = 0; i < bits.length; i++){
            if(bits[i] == 0){
                state = state == 1 ? 2 : 0;
            }else{
                state = state == 1 ? 2 : 1;
            }
        }
        
        return state == 0;
    }
}