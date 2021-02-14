#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int size = A.size();
        unordered_set<int> unique = {};
        int max_ele = INT_MIN;
        
        for(int i = 0; i < size; i++)
            max_ele = max(max_ele, A[i]);
        
        unsigned mask = 1 << 31;
        for(int i = 31; i >=0; i--){
            if(mask & max_ele)
                break;
            mask = mask >> 1;
        }
        
        max_ele = (mask << 1) - 1;
        
        for(int i = 0; i < size; i++)
        {
            int temp = A[i];
            unique.insert(temp);
            for(int j = i + 1; j < size; j++){
                temp =  temp | A[j];
                unique.insert(temp);
                if(temp >= max_ele)
                    break;
            }
        }
        return unique.size();
    }
};
