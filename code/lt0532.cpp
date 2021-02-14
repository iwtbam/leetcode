#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> record;
        if(k < 0)
            return 0;
        int pairs = 0;
       
        
        for(int i = 0; i < nums.size(); i++)
            record[nums[i]]++;
        
        for(auto& p:record){
            p.second--;
            if(record.count(p.first + k) && record[p.first + k]){
                cout << p.first << endl;
                pairs++;
                record[p.first + k]--;
            }
        }
        
        
        return pairs;
    }
};