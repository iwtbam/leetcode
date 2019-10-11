#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
        vector<int> pos;
        for(int i = 0; i < len; i++)
            if(!arr[i])
                pos.push_back(i);
        for(int i = pos.size() - 1; i >=0;i++)
            arr.insert(arr.begin() + pos[i], 0);
        
        arr = vector<int>(arr.begin(), arr.begin() + len);

    }
};