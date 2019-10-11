import java.util.ArrayList;

public class lt0071 {
    public String  simplifyPath(String path){
        ArrayList<String> paths = new ArrayList<String>();
        StringBuffer sb = new StringBuffer();
        int start = 0, stop = path.indexOf("/");
        while(stop!=-1){
            if(start!=stop){
                String temp = path.substring(start, stop);
                if(temp.equals("..")){
                    if(!paths.isEmpty())
                        paths.remove(paths.size()-1);
                }else if(!temp.equals(".")){
                    paths.add(path.substring(start, stop));
                }
            }
            start = stop+1;
            stop = path.indexOf("/", start);
        }
            
        String lastStr = path.substring(start);
        if(!lastStr.equals("")){
            if(lastStr.equals("..")){
                if(!paths.isEmpty())
                    paths.remove(paths.size() - 1);
            }else if(!lastStr.equals(".")){
                paths.add(lastStr);
            }
        }

        for(String item:paths){
            sb.append("/");
            sb.append(item);
        }
        
        if(sb.length() == 0)
            sb.append('/');
        
        return sb.toString();
    
    }

    public static void main(String[] args){
        lt0071 pro = new lt0071();
        String path = new String("/home/temp//33//2/2//2/");
        pro.simplifyPath(path);
        return;
    }
}