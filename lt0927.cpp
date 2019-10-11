#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int size = A.size(), s = 0;
        vector<int> ones = {};
        for(int i = 0; i < size; i++)
        {
            if(A[i])
                ones.push_back(i);
        }
        
        if(ones.size() % 3)
            return {-1, -1};
        
        if(ones.size() == 0)
            return {0, size-1};
    
        int num = ones.size() / 3;
        int i = ones[num - 1];
        int j = ones[num * 2 - 1];
        
        
        int zeros = size - ones.back() - 1;
        
        if(i + zeros < ones[num])
            i = i+zeros;
        
        if(j + zeros < ones[num*2])
            j = j+zeros;
        
        
        string v1 = calc_value(A, 0, i+1);
        string v2 = calc_value(A, i+1, j+1);
        string v3 = calc_value(A, j+1, size);
                
        if(v1 == v2 && v2 == v3)
            return {i, j+1};
         
        return {-1, -1};      
    }

    string calc_value(vector<int>& A, int start, int end){
        string ans = {};
        while(start < end && A[start] == 0)
            start++;
        
        for(; start < end; start++)
            ans.push_back(A[start] + '0');
        
        return ans;
    }
};