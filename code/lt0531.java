class Solution {
    public int findLonelyPixel(char[][] picture) {
        int rows = picture.length;
        if(rows == 0)
            return 0;
        int cols = picture[0].length;
        if(cols == 0)
            return 0;
        
        System.out.println(rows + " " + cols);
        
        int[] r = new int[rows];
        int[] c = new int[cols];
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(picture[i][j]=='B'){
                    r[i]++;
                    c[j]++;
                }
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(picture[i][j]=='B' && r[i] == 1 && c[j] == 1){
                    count++;
                }
            }
        }
        
        return count;
    }
}