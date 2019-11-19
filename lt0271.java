import java.util.*;


//2019-11-09:11-51:不优
public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        StringBuffer sb = new StringBuffer();
        for(String str : strs){
            int len = str.length();
            String token = String.format("%05d", len);
            sb.append(token);
            sb.append(str);
        }
        
        return sb.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        List<String> res = new ArrayList<>();
        while(s.length() != 0){
            String token = s.substring(0, 5);
            int len = Integer.parseInt(token);
            res.add(s.substring(5, 5 + len));
            s = s.substring(5 + len);
        }
        
        return res;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));