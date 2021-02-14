// https://leetcode-cn.com/problems/max-difference-you-can-get-from-changing-an-integer/
// max difference you can get from changing an integer
class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        size_t size = str.size();
        
        if(size == 1)
            return 8;
        
        char c1 = '0', c2 = '9', r1 = str[0], r2 = '9';
        char f = str[0];
        bool change = false;
        for(int i = 0; i < size; i++){
           if(i == 0){
               if(str[i]!='1'){
                   r1 = '1';
                   c1 = str[i];
                   change = true;
                   break;
               }
           }else{
               if(str[i]!='0' && str[i]!=f){
                   c1 = str[i];
                   r1 = '0';
                   change = true;
                   break;
               }
           }
        }
        
        for(int i = 0; i < size; i++){
            if(str[i] != '9'){
                c2 = str[i];
                break;
            }
        }
        
        string a = str, b = str;
        
        for(int i = 0; i < size; i++){
            if(str[i] == c1 && change){
                a[i] = r1;
            }
            
            if(str[i] == c2){
                b[i] = r2;
            }
        }
        // cout << stoll(b) << " " << stoll(a) << endl;
        return stoll(b) - stoll(a);
    }
};