// https://leetcode-cn.com/problems/stone-game-vi/
// stone game vi
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        size_t n = aliceValues.size();
   
        vector<int> indexs(n, 0);
        
        iota(indexs.begin(), indexs.end(), 0);

        sort(indexs.begin(), indexs.end(), [&](int i, int j){
            return aliceValues[i] + bobValues[i] > aliceValues[j] + bobValues[j];
        });

    

        int alice = 0, bob = 0;
        for(int i = 0; i < n ; i += 2){
            alice += aliceValues[indexs[i]];
            if(i + 1 < n)
                bob += bobValues[indexs[i + 1]];
        }


        if(alice > bob)
            return 1;
        if(alice < bob)
            return -1;
        return 0;
    }
};