// https://leetcode-cn.com/problems/find-the-winner-of-an-array-game/
// find the winner of an array game
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        size_t size = arr.size();
        int pos = max_element(arr.begin(), arr.end()) - arr.begin();
        if(k > size){
            return arr[pos];
        }
        
        if(k == 0)
            return arr[0];
        int cur = 0, win = 0;
        for(int i = 1; i < pos; i++){
            if(arr[cur] > arr[i]){
                win++;
            }else{
                win = 1;
                cur = i;
            }
            if(win == k)
                return arr[cur];
        }
        
        return arr[pos];

    }
};