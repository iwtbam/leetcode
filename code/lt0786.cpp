// https://leetcode-cn.com/problems/k-th-smallest-prime-fraction/
// k th smallest prime fraction
class Solution {
public:

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l = 0.0, r = 1.0;
        vector<int> ans(2, 0);
        while(r - l > 1e-9){
            double mid = (l + r) / 2;
            auto res = count(mid, arr);

           // cout << mid << ", " << res[0] << " " << res[1] << "/" << res[2] << endl;
            if(res[0] >= k){
                r = mid;
                ans[0] = res[1];
                ans[1] = res[2];
            }else{
                l = mid;
            }
        }
        return ans;
    }

    vector<int> count(double val, const vector<int>& arr){
        size_t n = arr.size(), i = 1, j = -1;
        vector<int> res(3, 0);
        for(int i = 1; i < n; i++){
            while(arr[j + 1] < val * arr[i])
                j++;
            if(j == -1)
                continue;

            res[0] += j + 1;

            if(arr[j] * res[2] >= arr[i] * res[1]){
                res[1] = arr[j];
                res[2] = arr[i];
            }
        }
        return res;
    }
};