// https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence/
// split array into fibonacci sequence
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        size_t size = S.size();
        vector<int> res;
        for(int i = 0; i < size; i++){
            long long n1 = stoll(S.substr(0, i + 1));
            if(S[0] == '0' && i > 0 || n1 > INT_MAX)
                return {};
            bool flag = true;
            for(int j = i + 1; j < size; j++){
                if(S[i + 1] == '0' && j - i > 1)
                    continue;
                long long n2 = stoll(S.substr(i + 1, j - i));
                if(n2 > INT_MAX)
                    break;
                res.clear();
                res.push_back(n1);
                res.push_back(n2);

                long long nc1 = n1, nc2 = n2;

                int k = j + 1;
                while(k < size){
                    long long n = nc1 + nc2;
                    if(n > INT_MAX)
                        break;
                    string sn = to_string(n);
                   
                    if(k + sn.size() > size || sn != S.substr(k, sn.size())){
                       
                        break;
                    }
                    res.push_back(n);
                    k += sn.size();
                    nc1 = nc2;
                    nc2 = n;
                }

                if(k == size && res.size() > 2)
                    return res;
            }
        }


        return {};
    }
};