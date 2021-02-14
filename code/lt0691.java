import java.util.*;

//2019-11-12:17-24
class Solution {
    public int minStickers(String[] stickers, String target) {
        int len = stickers.length;
        int[][] record = new int[len][];
        int[] sR = new int[26];

        for(int i = 0; i < len; i++){
            String sticker = stickers[i];
            record[i] = hash(sticker);
        }

        memos.put("", 0);
        return helper(record, target);
        // return memos.get(toKey(tR));
    }

    public int helper(int[][] hashes, String target){
        int len = hashes.length;

        if(memos.get(target) != null)
            return memos.get(target);
       
        int[] tR = new int[26];
        int minStep = Integer.MAX_VALUE;

        for(char c : target.toCharArray())
            tR[c - 'a']++;

        for(int i = 0; i < len; i++){
            StringBuffer sb = new StringBuffer();

            if(hashes[i][target.charAt(0) - 'a'] == 0)
                continue;

            for(int j = 0; j < 26; j++){
                if(tR[j] > 0){
                    for(int k = 0; k < Math.max(0, tR[j] - hashes[i][j]); k++)
                        sb.append((char)('a' + j));
                }
            }

            String s = sb.toString();
            int temp = helper(hashes, s);
            if(temp!=-1)
                minStep = Math.min(minStep, 1 + temp);
        }
        memos.put(target, minStep == Integer.MAX_VALUE ? -1 : minStep);
        return memos.get(target);
    }


    public int[] hash(String s){
        int len = s.length();
        int[] hash = new int[26];
        for(int i = 0; i < len; i++){
            hash[s.charAt(i) - 'a']++;
        }
        return hash;
    }

    public String toKey(int[] hash){
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i < 26; i++)
           sb.append(hash[i]).append('#');
        return sb.toString();
    }

    private Map<String, Integer> memos = new HashMap<>();
}


// 2019-11-12:16-34 超时
// class Solution {
//     public int minStickers(String[] stickers, String target) {
//         int len = stickers.length;
//         int[][] record = new int[len][];
//         int[] tR = hash(target);
//         int[] sR = new int[26];

//         for(int i = 0; i < len; i++){
//             String sticker = stickers[i];
//             record[i] = hash(sticker);
//             for(int j = 0; j < 26; j++)
//                 sR[j] = Math.max(record[i][j], sR[j]);
//         }

//         for(int i = 0; i < 26; i++){
//             if(tR[i]!=0 && sR[0]==0)
//                 return -1;
//         }

//         return helper(record, tR, 0);
//     }

//     public int helper(int[][] hashes, int[] tR, int step){
//         int len = hashes.length;

//         boolean isReturn = true;
//         for(int i = 0; i < 26; i++){
//             if(tR[i] > 0)
//                 isReturn = false;
//         }

//         if(isReturn)
//             return step;

//         int minStep = Integer.MAX_VALUE;

//         for(int i = 0; i < len; i++){
//             boolean isContinue = true;
//             for(int j = 0; j < 26; j++){
//                 if(tR[j] > 0 && hashes[i][j] > 0)
//                     isContinue = false;
//             }
//             if(isContinue)
//                 continue;

//             for(int j = 0; j < 26; j++)
//                 tR[j] = tR[j] - hashes[i][j];

//             minStep = Math.min(minStep, helper(hashes, tR, step + 1));

//             for(int j = 0; j < 26; j++)
//                 tR[j] = tR[j] + hashes[i][j]; 
//         }

//         return minStep;
//     }

//     public int[] hash(String s){
//         int len = s.length();
//         int[] hash = new int[26];
//         for(int i = 0; i < len; i++){
//             hash[s.charAt(i) - 'a']++;
//         }
//         return hash;
//     }
// }