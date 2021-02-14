#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <deque>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> pos;
        multiset<int> height = {0};
        vector<vector<int>> res = {};
        for(auto b: buildings)
        {
            pos.emplace(b[0], -b[2]);
            pos.emplace(b[1],  b[2]);
        }
        
        int m = 0;

        for(auto p :pos)
        {
            
            if(p.second < 0)
                height.insert(-p.second);
            else
                height.erase(height.find(p.second));
                
            if(m != *height.rbegin())
                res.emplace_back(p.first, *height.rbegin());
            m = *height.rbegin();
        }

        return res;        
    }
};

int main()
{
    pair<int, int> p1 = {1, 2};
    pair<int, int> p2 = {2, 3};

    std::ios::sync_with_stdio(false);

    multiset<pair<int, int>> p;
    p.emplace(1, 2);
    p.emplace(2, 3);
    p.emplace(0, 3);


    for(auto pp : p)
    {
        cout << pp.first << ends << pp.second << endl;
    }

    return 0;
    // cout << boolalpha << (p1 < p2) << endl;

    return 0;
}