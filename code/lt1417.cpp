#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reformat(string s) {
        vector<char> s1;
        vector<char> s2;
        size_t size = s.size();
        string res = "";
        
        for(int i = 0; i < size; i++){
            if(s[i] >='0' && s[i] <= '9'){
                s1.push_back(s[i]);
            }else{
                s2.push_back(s[i]);
            }    
        }
        
        
        int diff = s1.size() - s2.size();
        
        if(abs(diff) > 1)
            return res;
        
        if(s2.size() > s1.size()){
            s2.swap(s1);
        }
        
        for(int i = 0; i < size; i++){
            if(i % 2 == 1){
                res += s2[i / 2];
            }else{
                res += s1[i / 2];
            }
        }
        
        return res;
    }
};