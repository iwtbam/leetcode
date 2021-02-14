// https://leetcode-cn.com/problems/best-position-for-a-service-centre/
// best position for a service centre
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double l = 0.0, r = 100.0;
        for(int i = 0; i < 100; i++){
            double lmid = l + (r - l) / 3.0;
            double rmid = r - (r - l) / 3.0;
            if(calc(positions, lmid) > calc(positions, rmid)){
                l = lmid;
            }else{
                r = rmid;
            }
        }
        return calc(positions, l);
    }

    double calc(vector<vector<int>>& positions, double x){
        double l = 0, r = 100;
        for(int i = 0; i < 100; i++){
            double lmid = l + (r - l) / 3;
            double rmid = r - (r - l) / 3;
            if(sumdis(positions, x, lmid) > sumdis(positions, x, rmid)){
                l = lmid;
            }else{
                r = rmid;
            }
        }
    
        return sumdis(positions, x, l);  
    }

    double sumdis(vector<vector<int>>& positions, double x, double y){
        size_t size = positions.size();
        double res = 0;
        for(int i = 0; i < size; i++){
            res += dis(positions[i][0], positions[i][1], x, y);
        }
        return res;
    }
  
    double dis(double x1, double y1, double x2, double y2){
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
};
