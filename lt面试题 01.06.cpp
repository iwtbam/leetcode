// https://leetcode-cn.com/problems/compress-string-lcci/
// compress string lcci
class Solution {
public:
    string compressString(string S) {
        if(S.size() == 0)
            return S;
        string cs;
        int num = 0, size = S.size();
        for(int i = 0; i < size - 1; i++){
            if(S[i] == S[i + 1]){
                num++;
            }else{
                cs.push_back(S[i]);
                cs += to_string(num + 1);
                num = 0;
            }
        }

        cs.push_back(S[size - 1]);
        cs += to_string(num + 1);

        return cs.size()  >=  size ? S : cs;
    }
};