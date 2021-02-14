// https://leetcode-cn.com/problems/find-positive-integer-solution-for-a-given-equation/
// find positive integer solution for a given equation
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        int lx = search1(cf, 1, 1000, 1000, z, false);
        int rx = search2(cf, 1, 1000, 0, z, false);
        int ly = search1(cf, 1, 1000, rx, z, true);
        int ry = search2(cf, 1, 1000, lx, z, true);

        //cout << lx << " " << rx << " " << ly << " " << ry << endl;
       
        vector<vector<int>> res;
        vector<int> can(2, 0);
        for(int x = lx; x <= rx; x++){
            for(int y = ly; y <= ry; y++){
                if(cf.f(x, y) == z){
                    can[0] = x;
                    can[1] = y;
                    res.emplace_back(can);
                }
            }
        }

        return res;

    }

    int search1(CustomFunction& cf, int l, int r, int val, int target, bool change){
        while(l < r){
            int mid = (l + r) >> 1;
            int x = mid, y = val;
            if(change)
                swap(x, y);
            if(cf.f(x, y) >= target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }

    int search2(CustomFunction& cf, int l, int r, int val, int target, bool change){
        while(l < r){
            int mid = (l + r + 1) >> 1;
            int x = mid, y = val;
            if(change)
                swap(x, y);
            if(cf.f(x, y) <= target){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }
};