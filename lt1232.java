class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int len = coordinates.length;
        if(len <= 2)
            return true;
        int[] p0 = coordinates[0];
        int[] p1 = coordinates[1];
        double k = p0[0] - p1[0] == 0 ? VK : (p1[1] - p0[1]) * 1.0 / (p1[0] - p0[0]);
        for(int i = 2; i < len; i++){
            int[] p2 = coordinates[2];
            double k1 = p2[0] - p0[0] == 0 ? VK : (p2[1] - p0[1]) * 1.0 / (p2[0] - p0[0]);
            if(Math.abs(k - k1) > err)
                return false;
        }

        return true;
    }

    private final double VK = Double.MAX_VALUE;
    private final double err = 0.00001;
}