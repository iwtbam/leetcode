// https://leetcode-cn.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
// filter restaurants by vegan friendly price and distance
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> candidate = {};
        size_t res_num = restaurants.size();
        for(int i = 0; i < res_num; i++){
            auto& restaurant = restaurants[i];
            if(restaurant[2] == 0 && veganFriendly == 1)
                continue;
            if(restaurant[3] > maxPrice)
                continue;
            if(restaurant[4] > maxDistance)
                continue;
            candidate.push_back(restaurant);
        }
        
        auto cmp_func = [](const vector<int>& v1, const vector<int>& v2){
          return v1[1] == v2[1] ? v1[0] > v2[0] : v1[1] > v2[1];
        };
        
        sort(candidate.begin(), candidate.end(), cmp_func);
        
        vector<int> res = {};
        
        size_t can_num = candidate.size();
        
        for(int i = 0; i < can_num ; i++)
            res.push_back(candidate[i][0]);
        return res;
    }
};