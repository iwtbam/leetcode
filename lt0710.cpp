#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        int blacklist_size = blacklist.size();
        set<int> unique_blacklist = {blacklist.begin(), blacklist.end()};
        this->N = N - blacklist_size;
        int start = this->N;
        for(int val : unique_blacklist){
            if(val >= this->N)
                break;
            while(unique_blacklist.count(start))
                start++;
            backlist_map[val] = start++;
        }
    }
    
    int pick() {
        int rand_num = rand() % this->N;
        if(backlist_map.count(rand_num))
            rand_num = backlist_map[rand_num];
        return rand_num;
    }

    int N;
    unordered_map<int, int>  backlist_map;
};
