// 2019-11-16:20-43 超时
// class Solution {
//     public String minWindow(String S, String T) {
//         int p = -1, minLen = Integer.MAX_VALUE;
//         int sL = S.length(), tL = T.length();
//         if(sL < tL || tL == 0)
//             return new String("");
//         char sc = T.charAt(0);
//         int pos = S.indexOf(sc);
//         while(pos!=-1 && pos + tL <= sL){
//             int len = 0;
//             int sI = pos, tI = 0;
//             while(sI < sL && tI < tL){
//                 if(S.charAt(sI) == T.charAt(tI))
//                     tI++;
//                 sI++;
//             }


//             if(pos == sL && tI < tL)
//                 return new String("");
            
//             if(tI == tL && sI - pos + 1 < minLen){
//                 p = pos;
//                 minLen = sI - pos ;
//             }
//             pos = S.indexOf(sc, pos + 1);
//         }

//         if(p == -1)
//             return new String("");

//         return S.substring(p, p + minLen);
//     }
// }