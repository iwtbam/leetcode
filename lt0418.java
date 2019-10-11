class Solution {
    public int wordsTyping(String[] sentence, int rows, int cols) {
        int len = sentence.length;
        int[] record = new int[sentence.length];
        int[] memos = new int[rows + 1];
        for(int i = 0; i < len; i++)
            record[i] = sentence[i].length();
        int row = 0, sIndex = 0;
        
        while(row < rows){
            int col = cols;
            while(record[sIndex % len] <= col){
                col -= record[sIndex % len];
                col--;
                sIndex++;
            }
            row++;
            memos[row] = sIndex / len;
            if(sIndex !=0 && sIndex % len == 0){
                int num = rows / row;
                return num * memos[row] + memos[rows - row * num];
            }
        }
    
        return sIndex / len;
    }
}

//  循环节优化错
// class Solution {
//     public int wordsTyping(String[] sentence, int rows, int cols) {
//         int len = sentence.length;
//         int sIndex = 0, pos = 0, count = 0;
//         int total = rows * cols;
//         int[] record = new int[rows + 1];
//         while(pos < total){

//             if((sentence[sIndex % len].length() + pos % cols)  > cols){
//                 pos = (pos / cols + 1) * cols; 
                
//             }else{
                
//                 pos = pos + sentence[sIndex % len].length();
//                 if(pos % cols != 0)
//                     pos += 1;
//                 sIndex++;
//             }
            
//             if(pos % cols == 0)
//                 record[pos / cols] = sIndex / len;
            
//             if(sIndex!=0 && pos % cols == 0 && sIndex % len == 0){
//                 int num = pos / cols;
//                 int duration = total / pos;
//                 sIndex = (total / pos) * (sIndex / len);
//                 return sIndex + record[rows - num * duration];
//             }
            
//         }
        
        
//         return sIndex / len;
//     }
// }

//2019-10-07：12-06 暴力超时
// class Solution {
//     public int wordsTyping(String[] sentence, int rows, int cols) {
//         int len = sentence.length;
//         int sIndex = 0, pos = 0, count = 0;
//         int total = rows * cols;
//         while(pos < total){

//             if((sentence[sIndex % len].length() + pos % cols)  > cols){
//                 pos = (pos / cols + 1) * cols; 
                
//             }else{
                
//                 pos = pos + sentence[sIndex % len].length();
//                 if(pos % cols != 0)
//                     pos += 1;
                   
//                 sIndex++;
//             }    
//         }
               
//         return sIndex / len;
//     }
// }