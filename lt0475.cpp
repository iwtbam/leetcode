// https://leetcode-cn.com/problems/heaters/
// heaters
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = 1e9;
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(houses, heaters, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return l;
    }

    bool check(const vector<int>& houses, const vector<int>& heaters, int r){
        int hsize = heaters.size(), house_size = houses.size(), no = 0;
        for(int i = 0; i < hsize; i++){
            int lb = heaters[i] - r;
            int rb = heaters[i] + r;

            while(no < house_size){
                if(houses[no] < lb)
                    return false;
                if(houses[no] > rb)
                    break;
                no++;
            }
        }
        return no == house_size;
    }
};