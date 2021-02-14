#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        vector<int> hash(size);
        for(int i = 0; i < size; i++){
            int wsize = words[i].size();
            for(int j = 0; j <wsize; j++){
                hash[i]|= 1 << (words[i][j] - 'a' + 1);
            }
        }

        int res = 0;

        for(int i = 0; i < size - 1; i++){
            for(int j = i + 1; j < size; j++){
                if((hash[i] & hash[j]) == 0){
                    int product = words[i].size() * words[j].size();
                    res = max(res, product);
                }
            }
        }

        return res;        
    }
};