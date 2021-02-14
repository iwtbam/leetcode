class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {    
        int[] res = new int[queries.length];
        int[] q = new int[queries.length];
        int[] w = new int[words.length];
        for(int i = 0; i < queries.length; i++){
            q[i] = func(queries[i]);
        }

        for(int i = 0; i < words.length; i++){
            w[i] = func(words[i]);
        }

        for(int i = 0; i < queries.length; i++){
            int count = 0;
            for(int j = 0; j < words.length; j++){
                if(q[i] < w[j])
                    count++;
            }
            res[i] = count;
        }
        
        return res;
    }

    public int func(String str){
        int[] record = new int[26];
        for(int i = 0; i < str.length(); i++){
            record[str.charAt(i) - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(record[i]!=0)
                return record[i];
        }
        return 0;
    }
}