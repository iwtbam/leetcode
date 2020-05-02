#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, unordered_map<string, int>> record;
        map<string, int> foodrecord;
        set<string> foods;
        for(const auto& order : orders){
            string tablename = order[1];
            string fooditem = order[2];
            record[stoi(tablename)][fooditem]++;
            foods.insert(fooditem);
        }
        
        size_t i = 1, size = foods.size();
        for(auto& food : foods){
            foodrecord[food] = i++;
        }
        
        vector<vector<string>> res = {};
        
        vector<string> headers = {"Table"};
        headers.insert(headers.end(), foods.begin(), foods.end());
        
        res.push_back(headers);
        
        
        for(const auto& item : record){
            vector<string> order = {size + 1, "0"};
            order[0] = to_string(item.first);
            for(auto& fi : item.second){
                order[foodrecord[fi.first]] = to_string(fi.second);
            }
            res.push_back(order);
        }
        
        return res;
    }
};