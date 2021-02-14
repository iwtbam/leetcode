class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        int len1 = s1.length();
        int len2 = s2.length();
        int[] counter = new int[n1 + 1];
        int[] record =  new int[n1 + 1];
        int count = 1, pos = 0, sum = 0;
        
        while(count <= n1){
            for(int i = 0; i < len1; i++){
                if(s1.charAt(i) == s2.charAt(pos)){
                    if(pos == len2 - 1){
                        sum++;
                        pos = 0;
                    }else{
                        pos++;   
                    }
                }
            }
            
            counter[count] = sum;
            record[count] = pos;
            
            for(int i = 0; i < count; i++){
                if(record[i] == pos){
                    int interval = count - i;
                    int N = (n1 - i) / interval;
                    int cnt1 = N * (counter[count] - counter[i]);
                    int cnt2 = counter[i + (n1 - i) % interval];
                    return (cnt1 + cnt2) / n2;
                }
            }
            
            count++;
        }
        
        return counter[n1] / n2;
    }
}