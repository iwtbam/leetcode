class Solution {
    
    int[] months = new int[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    public int numberOfDays(int Y, int M) {
        if(M == 2)
            return isLeap(Y) ? 29 : 28;
        return months[M - 1];
    }
    
    public boolean isLeap(int year){
        if(year % 100 == 0)
            return year % 400 == 0;
        return year % 4 == 0;
    }
}