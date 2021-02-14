class Solution {
    public String addStrings(String num1, String num2) {
        int co = 0, len1 = num1.length(), len2 = num2.length();
        StringBuffer sb = new StringBuffer();
        int left  = len1 - 1;
        int right = len2 - 1;
        while(left >= 0 || right >= 0 || co > 0){
            int n1 = left >= 0 ? num1.charAt(left) -  '0' : 0;
            int n2 = right >=0 ? num2.charAt(right) - '0' : 0;
            int num = n1 + n2 + co;
            co  = num / 10;
            num = num % 10;

            sb.append((char)(num + '0'));
            left--;
            right--;
        }
        
        
     
        return sb.reverse().toString();
    }
}


// class Solution {
//     public String addStrings(String num1, String num2) {
//         int co = 0, len1 = num1.length(), len2 = num2.length();
//         StringBuffer sb = new StringBuffer();
//         int left  = len1 - 1;
//         int right = len2 - 1;
//         while(left >= 0 && right >= 0){
//             int num = num1.charAt(left) - '0' + num2.charAt(right) - '0' + co;
//             co  = num / 10;
//             num = num % 10;

//             sb.append((char)(num + '0'));
//             left--;
//             right--;
//         }
        
//         while(left >= 0){
//             int num = num1.charAt(left) - '0' + co;
//             co  = num / 10;
//             num = num % 10;
//             sb.append((char)(num + '0'));
//             left--;
           
//         }
        
//         while(right >= 0){
//             int num = num2.charAt(right) - '0' + co;
  
//             co = num / 10;
//             num = num % 10;
//             sb.append((char)(num + '0'));
//             right--;
//         }
        
//         if(co != 0)
//             sb.append((char)(co + '0'));
        
     
//         return sb.reverse().toString();
//     }
// }