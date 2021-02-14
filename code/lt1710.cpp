// https://leetcode-cn.com/problems/maximum-units-on-a-truck/
// maximum units on a truck
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& v1, const vector<int>& v2){
           return v1[1] > v2[1]; 
        });
        
        size_t size = boxTypes.size();
        
        int ans  = 0;
        for(int i = 0; i < size; i++){
            if(boxTypes[i][0] >= truckSize){
                ans += truckSize * boxTypes[i][1];
                break;
            }
            ans += boxTypes[i][0] * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
        }
        
        return ans;
    }
};