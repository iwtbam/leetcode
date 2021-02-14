// https://leetcode-cn.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/
// detect pattern of length m repeated k or more times
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        const int P = 13331;
        size_t size = arr.size();
        
        vector<unsigned long long> hashs(size + 1, 0);
        vector<unsigned long long> ps(size + 1, 1);
        
        for(int i = 0; i < size; i++){
            hashs[i + 1] = hashs[i] * P + arr[i];
            ps[i + 1] = ps[i] * P;
        }
        
        for(int i = 0; i < m; i++){
            int num = 1;
            int max_num = 1;
            unsigned long long pre = 0;
            for(int j = i + m; j <= size; j += m){
                unsigned long long hash = hashs[j] - hashs[j - m] * ps[m];    
                if(j == i + m){
                    pre = hash;
                    continue;
                }
                if(hash == pre){
                    num++;
                }else{
                    num = 1;
                }
                max_num = max(num, max_num);
                pre = hash;
            }
            if(max_num >= k)
                return true;
        }
        
        return false;
    }
};