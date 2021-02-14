class Solution {
    public double largestTriangleArea(int[][] points) {
        double maxArea = 0.0;
        int len = points.length;
        
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++){
                for(int k = j + 1; k < len; k++){
                    maxArea = Math.max(maxArea, area(points[i], points[j], points[k]));
                }
            }
        }
        
        return maxArea;
    }
    
    public double area(int[] p, int[] p1, int[] p2){
        int vx1 = p1[0] - p[0];
        int vy1 = p1[1] - p[1];
        int vx2 = p2[0] - p[0];
        int vy2 = p2[1] - p[1];
        return (double)Math.abs(vx1 * vy2 - vy1 * vx2) / 2.0;
    }
}