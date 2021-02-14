// https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target/
// sum of mutated array closest to target
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int size = arr.size();
        int lb = target / size;
        int ub = lb + 1;

        vector<int> eles = {};
        for(int i = 0; i < size; i++){
            if(arr[i] > lb){
                eles.push_back(arr[i]);
            }
        }

        sort(eles.begin(), eles.end());

        for(int ele: eles){
            if(sum(arr, ele) - target >= 0){
                ub = ele;
                break;
            }else{
                lb = ele;
            }
        }

        int err = INT_MAX;
        int res = lb;

        for(int i = lb; i <= ub; i++){
            int cur_err = abs(sum(arr, i) - target); 
            if(cur_err < err){
                err = cur_err;
                res = i;
            }
        }

        return res;
    }

    int sum(const vector<int>& arr, int threshold){
        int res = 0;
        for(int num : arr){
            res += min(num, threshold);
        }
        return res;
    }
};