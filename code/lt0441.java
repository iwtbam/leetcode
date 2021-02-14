class Solution {
    public int arrangeCoins(int n) {
        
        double x = (-1 + Math.sqrt(1 + 8 * (n * 1.0)))/2;
        return (int)Math.floor(x);
    }
}