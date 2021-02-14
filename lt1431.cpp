// https://leetcode-cn.com/problems/kids-with-the-greatest-number-of-candies/
// kids with the greatest number of candies
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_e = *max_element(candies.begin(), candies.end());
        size_t size = candies.size();
        vector<bool> res(size, false);
        for(int i = 0; i < size; i++){
            if(extraCandies + candies[i] >= max_e){
                res[i] = true;
            }
        }
        
        return res;
    }
};